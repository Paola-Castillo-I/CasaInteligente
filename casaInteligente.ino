#include <Servo.h>
#include <SPI.h>
#include <Ethernet.h>
 
/* Variables para manejar la puerta */
int botonPuerta = 2;
int estadoBotonPuerta = 0;
int contadorPulsaciones = 0;
int banderaAlarma = 0;
int estadoPuerta = 0;
Servo motorPuerta;

/* Variables para manejar la ventana */
int botonVentana = 4;
int contadorPulsacionesVentana = 0;
int estadoBotonVentana = 0;
int estadoVentana = 0;
Servo motorVentana;

/* Variables para manejar la alarma */
int sensorMovimientoAlarma = 6;
int pinAlarma = 7;
int lecturaMovimientoAlarma = 0;
int cant = 0;

/* Variables para manejar conexión ethernet */
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };   //Direccion Fisica MAC
IPAddress ip(10,1,100,220); 
EthernetServer server(80);                             //Se usa el puerto 80 del servidor     
String readString;

void setup () {
  Serial.begin(9600); 
  pinMode(botonPuerta, INPUT);
  pinMode(botonVentana, INPUT);
  pinMode(sensorMovimientoAlarma, INPUT);
  pinMode(pinAlarma, OUTPUT);
  motorPuerta.attach(3);
  motorPuerta.write(90);
  motorVentana.attach(5);
  motorVentana.write(50);
  Ethernet.begin(mac,ip); // Inicializa la conexion Ethernet y el servidor
  server.begin();
  Serial.print("El Servidor es: ");
  Serial.println(Ethernet.localIP());    // Imprime la direccion IP Local
}

/* PROGRAMA PRINCIPAL */

void loop () {
  /*Actualizamos conexión ethernet*/
  EthernetClient client = server.available();
  if (client) {
    while (client.connected()) {   
      if (client.available()) {
        char c = client.read(); //Lee caracter por caracter HTTP
        if (readString.length() < 100) {  
          readString += c; //Almacena los caracteres a un String
        }
         // si el requerimiento HTTP fue finalizado
        if (c == '\n') {          
          Serial.println(readString); //Imprime en el monitor serial
          client.println("HTTP/1.1 200 OK");           //envia una nueva pagina en codigo HTML
          client.println("Content-Type: text/html");
          client.println("Connection: close");
          client.println();
          client.println("<!DOCTYPE html>");      
          client.println("<HTML>");
          client.println("<HEAD>");
          client.println("<TITLE>Casa Inteligente</TITLE>");
          client.println("</HEAD>");
          client.println("<BODY>");
          client.println("<CENTER>");
          client.println("<H1><b><h1>Conexion ethernet</h1></b></H1>");
          client.println("<br />");
          
          client.println("<hr />");
          client.println("<hr />");
          client.println("<br />");
          client.println("<br />");

          client.println("<b>Manejador ventana</b>");
          client.println("<br />");
          client.println("<br />"); 
          client.println("<a href=\"/?abrirVentana\"\">Abrir ventana</a>");
          client.println(" | | | ");
          client.println("<a href=\"/?cerrarVentana\"\">Cerrar ventana</a><br />"); 
          client.println("<br />");
          client.println("<hr />");
          client.println("<br />"); 
          client.println("<p>Por: Paola Castillo Irene - Roberto Ismael Ramírez Rios</p>");  
          client.println("<br />");
          client.println("</CENTER>");
          client.println("</BODY>");
          client.println("</HTML>");
   
          delay(100);
          client.stop();//detiene el cliente servidor
         
          //control del arduino si un boton es presionado
          if (readString.indexOf("?abrirVentana") >0){
            motorVentana.write(-100);
            estadoVentana = 1;
           }
           if (readString.indexOf("?cerrarVentana") >0){
            motorVentana.write(85);
            estadoVentana = 0; 
           }
                  
          delay(100);
          client.stop(); //detiene el cliente servidor     
          readString=""; // Limpia el String(Cadena de Caracteres para una nueva lectura  
        }
      }
    }
  }
  
  /*Escuchar boton puerta*/
  estadoBotonPuerta = digitalRead(botonPuerta); 
  if (estadoBotonPuerta == 1){
    manejadorServoPuerta();
  }

  /*Escuchar boton ventana*/
  estadoBotonVentana = digitalRead(botonVentana); 
  if (estadoBotonVentana == 1){
    manejadorServoVentana();
  }
  
  /*Escuchar sensor movimiento alarma*/
  lecturaMovimientoAlarma = digitalRead(sensorMovimientoAlarma); 
  if (lecturaMovimientoAlarma == HIGH){
    manejadorAlarma();  
  }
}

/* Funcion para manejar la puerta */
void manejadorServoPuerta(){
  long startTime = millis();
  while(millis() - startTime < 1000)
  {
    estadoBotonPuerta = digitalRead(botonPuerta); 
    if (estadoBotonPuerta == 1)
    {
      contadorPulsaciones = contadorPulsaciones + 1;
      delay(200);
      Serial.println(contadorPulsaciones, DEC); 
    } 
  }
  if (contadorPulsaciones >= 2){
    if(estadoPuerta == 0){
      if (banderaAlarma == 0){
        Serial.println("Se activo alarma");
        banderaAlarma = 1;
      }
      else {
        Serial.println("Se desactivo alarma");
        banderaAlarma = 0;
        digitalWrite(pinAlarma, LOW);
      }
    }
    else {
      Serial.println("Puerta abierta, no se puede activar la alarma");
      banderaAlarma = 0;
    }
  }
  else {
    if (banderaAlarma == 0){
      if (estadoPuerta == 0){
        Serial.println("Abrir puerta");
        motorPuerta.write(-80);
        estadoPuerta = 1;
      }
      else {
        Serial.println("Cerrar puerta");
        motorPuerta.write(80);
        estadoPuerta = 0;
      }
    }
    else {
      Serial.println("No se abre, alarma activa");
    }
  }
  contadorPulsaciones = 0;
}

/* Funcion para manejar la ventana */
void manejadorServoVentana() {
   long startTime = millis();
  while(millis() - startTime < 1000){
    estadoBotonVentana = digitalRead(botonVentana); 
    if (estadoBotonVentana == 1){
      contadorPulsacionesVentana = contadorPulsacionesVentana + 1;
      delay(200);
      Serial.println(contadorPulsacionesVentana, DEC); 
    } 
  }

  if (contadorPulsacionesVentana >= 1){
    if(estadoVentana == 0){
      Serial.println("Abrir ventana");
      motorVentana.write(-100);
      estadoVentana = 1;
    } else {
      Serial.println("Cerrar ventana");
      motorVentana.write(85);
      estadoVentana = 0;
    }
  }
}

/* Funcion para manejar la alarma */
void manejadorAlarma(){
    if (banderaAlarma == 1) {
      digitalWrite(pinAlarma, HIGH);
      Serial.println("INTRUSO");
     } else {
          digitalWrite(pinAlarma, LOW);
          Serial.println("Hay presencia autorizada");
          cant = 0;  
     }
}

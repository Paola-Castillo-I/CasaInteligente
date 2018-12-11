#include <Servo.h> 
 
Servo servo1;  //creamos un objeto servo 
Servo servo2;  //creamos un objeto servo
void setup() 
{ 
  servo1.attach(3);  // asignamos el pin al servo.
  servo2.attach(4);  // asignamos el pin al servo.
   Serial.begin(9600);
} 
 
void loop() 
{ 
  int angulo1 = map(analogRead(A0), 0, 1023, 0, 180);  // escalamos la lectura a un valor entre 0 y 180
  int angulo2 = map(analogRead(A1), 0, 1023, 0, 180);  // escalamos la lectura a un valor entre 0 y 180  
  servo1.write(angulo1);  // enviamos el valor escalado al servo.
  servo2.write(angulo2);  // enviamos el valor escalado al servo.
  //----Enviamos los ángulos serialmente--------------
  Serial.print("Angulos  1: ");
  Serial.print(angulo1);
  Serial.print("  2: ");
  Serial.print(angulo2);
  delay(10);            
}

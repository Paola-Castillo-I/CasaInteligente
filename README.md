##**CASA INTELIGENTE**<br>
Instituto  Tecnológico de León<br>
Ingeniería en Sistemas Computacionales<br>
Sistemas Programables<br>
Trabajo: Sistema de control de red con Arduino<br>
Profesor: Ing. Levy Rojas Carlos Rafael<br>
Presentado por: Paola Castillo Irene - Roberto Ismael Ramírez Rios<br>
Horario: Martes y Jueves de 08:45 am - 10:30 am<br>
Agosto-Diciembre 2018 <br>
Envío de instrucciones mediante internet con arduino<br>

## **DESCRICIÓN**

El siguiente proyecto consiste en un sistema de control de red para una Casa, simulando las funnciones de alarma cuando detecta movimiento alrededor de la casa y cerrado automatico de las puertas cuando se activa la alarma. Este sistema de control cumple con los siguientes requisitos:
  * Incluye 3 sensores y dos actuadores.
  * El sistema de control muestra los movimientos que detectan los sensores y tona las acciones necesarias en consecuencia.
  
Las caracteristicas del sistema de control son:
  * Se usa para el control de seguridad de la casa mediante sensores y actuadores.
  * Muestra al usuario la información sobre lo que pasa a traves de la ip mediante una página web.
  * Se pueden tomar acciones mediante la página web para el control de la casa.
  * Cada que detecta un movimiento el sensor activa una alarma y esta hace que se cierren tanto la puerta como la ventana y no se permita       el acceso.

## **MATERIAL**

De Hardware

  * Arduino Uno
  * Ethernet Shield 17/20
  * Protoboard
  * 2 servomotores SG90
  * 1 Piezoelectronic Buzzer
  * 2 sensores de movimiento PIR
  * Led's
  * Resistencias 220 ohms
  * Cables Dupont(Jumpers) macho macho
  * Cables Dupont(Jumpers) macho hembra
  * Cable de red
  * Cable USB para arduino
  * Computadora
  
De Software

  * Arduino IDE
  * Librería Servo
  * Librería SPI
  * Librería Ethernet
  
## **MONTAJE DEL CIRCUITO**
## **Sensor PIR**
  * Conectamos el sensor pir al protoboard, su pata ziquierda va a tierra, su pata de en medio va a la placa Arduino en el pin 2, la       pata derecha va a voltaje. Para el segundo sensor PIR se conectara al pin 4 de la placa Arduino.
  * Después conectamos la bocina al protoboard, la pata izquierda a tierra y la pata derecha se conecta donde estara la resistencia de     220 ohms que se conecta con los led's, después se pone un cable dupont que ira conetado a la placa Arduino en el pin 3.
  * Para los leds se conectara al protoboard, la pata mas corta ira a voltaje y la pata mas larga se conectara con una resistencia de       220 ohms como ya se había comentado.
  <img src="https://github.com/Paola-Castillo-I/CasaInteligente/blob/master/Imagenes/sensorPIR.jpg" width="400" height="400">
  
## **Servomotores**
  * Conectamos el primer servomotor al protoboard, su pata izquierda ira conectado a tierra, su pata de en medio ira a voltaje y la         pata derecha ira conectada al pin 9 de la placa Arduino.
  * Para el segundo servomotor se hara lo mismo que en primer servomotor pero la pata derecha ira conectada al pin 10 de la placa           arduino.
   <img src="https://github.com/Paola-Castillo-I/CasaInteligente/blob/master/Imagenes/conexionServo.png" width="400" height="400">
   
## **Ethernet Shield""
  * Se conecta el pin VCC a la placa Arduino en voltaje de 3.3V
  * El pin GND se conecta a la placa Arduino en GND
  * El pin SCK se conceta a la placa Arduino en Pin 13
  * El pin SO se conecta a la placa Arduino en Pin 12
  * El pin SI se conecta a la placa Arduino en Pin 11
  * El pin CS se conecta a la placa Arduino en Pin 10
  <img src="https://github.com/Paola-Castillo-I/CasaInteligente/blob/master/Imagenes/conexion.jpg" width="400" height="400">
  <img src="https://github.com/Paola-Castillo-I/CasaInteligente/blob/master/Imagenes/cableado2.jpg" width="400" height="400">
  
## **IMAGENES DEL PROYECTO**
  <img src="https://github.com/Paola-Castillo-I/CasaInteligente/blob/master/Imagenes/casa1.jpg" width="400" height="400">
  <img src="https://github.com/Paola-Castillo-I/CasaInteligente/blob/master/Imagenes/casa2.jpg" width="400" height="400">
  <img src="https://github.com/Paola-Castillo-I/CasaInteligente/blob/master/Imagenes/casa3.jpg" width="400" height="400">
  
## **CONTACTOS**
Cualquier duda o aclaración, puede enviar mensaje al siguiente correo electrónico:<br>
Correo electrónico - 14241042@itleon.edu.mx<br>
Elaborado por: Paola Castillo Irene

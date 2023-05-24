/*
    Vamos a usar los arduinos como modems o adaptadores de RED
    
    Lee y escribe datos en dos puertos serie, uno es de hardware el segundo es de software
    para probarlo se requiere dos arduinos y dos computadoras
    los arduinos deben conectarse entre si por los pines 2 y 3
    ademas cada arduino debe conectarse a una computadora, en la cual debera 
    estar debidamente asignado el puerto serie
    Una vez conectados los arduinos, podra utilizar el monitor serial para capturar de teclado
    el texto que desea enviar a la otra computadora
*/

#include<SoftwareSerial.h>

const int rxpin=2;
const int txpin=3;
const char LF=10;
SoftwareSerial serial_arduino(rxpin,txpin);

void setup()
{
    Serial.begin(9600)
    Serial_arduino.begin(9600);
}


String input_1, input_2;
void loop()
{
    if(Serial.available())
    {
        input_1 = Serial.readStringUntil(LF);
        Serial_arduino.prinln(" << "+input_1);  
        Serial.println(input_1);     
    }

    if(serial_arduino.available())
    {
        input_2 = serial_arduino.readStringUntil(LF);
        Serial.prinln(" << "+input_2);  
        serial_arduino.println(input_1);     
    }
}
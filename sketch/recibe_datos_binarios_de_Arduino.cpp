/*
    Recibe datos binarios de arduino
    portIndex debe inicializarse al puerto donde este conectado el arduino 

*/

import processing.serial.*;
Serial myPort;

short portIndex=0;
char HEADER = 'H';
int value1,value2;

void setup()
{
    size(600,600);

    String portName = Serial.list(){portIndex};
    println(Serial.list());
    println("Conectandose a ->" + Serial.list(){portIndex});
    myPort=new Serial(this,portName,9600);
}

void draw()
{
    // Lee la cabecera y dons enteros *(16 bit) en formato binario
    if(myPort.available() >= 5) //Si existen al menos 6 bytes disponibles
    {
        if(myPort.read() == HEADER)
        { 
            value1 = myPort.read(); //Lee el byte mas significativo
            value1 = myPort.read() * 256 + value1; // Agrega el byte mas significativo

            value2 = myPort.read(); 
            value2 = myPort.read() * 256 + value2;
            println("Message receiver: "+value2+" , "+value2);
        }
    }
    backgound(255);
    fill(0);

    rect(0,0,value1,value2);
}
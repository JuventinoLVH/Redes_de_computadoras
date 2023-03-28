/*
    Sketch Envia datos binarios a Arduino
    Lenguage processing
*/

import processing.serial.*;
const int indice_puerto = 0;

Serial myPort;
public static final char HEADER = 'H';
public static final char MOUSE_TAG = 'M';
void setup()
{
    seize(512,512);
    String portName = Serial.list()[indice_puerto];
    myPort = new Serial(this,portName,96000);    
}

void draw(){

}

void SerialEvent(Serial p)
{
    String inString = myPort.readStringUntil('\n');
    if(inString != null)
    {
        print(inString);
    }
}

void mousePressed()
{
    sendMessage(MOUSE_TAG,mouseX,mouseY);
}

void sendMessage(char tag,int x,int y)
{
    myPort.write(HEADER);
    myPort.write(tag);
    myPort.write((char)(x/256));
    myPort.write(x & 0xff);
    myPort.write(char)(y/256));
    myPort.write(y & 0xff);
    
}




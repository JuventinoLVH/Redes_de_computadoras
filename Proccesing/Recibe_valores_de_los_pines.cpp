/*
    Recibe valores de pines de arduino
    Processing
    Probarlo con sketch Envia valores de pines
*/

import processing.serial.*;
Serial myPort;
short portindex = 1;

char HEADER = 'H';

void setup()
{
    size(200,200);
    String portName = Serial.list()[portindex];
    println("Conectando a -> "+Serial.list()[portindex]);
    myPort = new Serial(this,portName,9600);
}

void draw()
{
    int val;
    if(myPort.available() >= 15)
    {
        if(myPort.read() == HEADER)
        {
            println("mensaje recivido");
            val = readArduinoInt();

            for(int pin=2, bit =1 ; pin <= 13 ; ++pin)
            {
                print("Digital pin "+pin+" =");
                int isSet = (val & bit);
                if(isSet == 0 )
                {
                    println("0");
                }
                else
                {
                    println("1");    
                }

                bit = bit*2;
            }
            println();
        }

        for(int i=0;i<6;++i)
        {
            val = readArduinoInt();
            println("puerto analogico " +i+ " = " + val);           
        }
        println("...");
    }
}

int readArduinoInt()
{
    int val;
    
    val = myPort.read();
    val = myPort.read();
    return val;
}
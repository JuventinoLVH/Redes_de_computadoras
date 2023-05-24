/*
    Recibe multiples campos binarios graba en archivo
        -Processing
        -Basado en codigo Recibe valores de pines de Arduinos, esta version graba los datos
            en un archivo 
        -Para probarlo cargue el sketch "Envie_Valores_de_pines" en arduino y conectalo al
            puerto USB
        -Portindex debe de ser inicializado con el numero de puerto donde esta conectado el arduino
        -Presione cualquier tecla para dejar de registrar datos en el archivo
*/

import processing.serial.*;
import java.text.*;
import java.util.*;

PrintWriter output;
DateFormat fnameFormat = new SimpleDateFormat("yyMMdd_HHmm");
DateFormat timeFormat = new SimpleDateFormat("hh:mm:ss");
String fileName;
Serial myPort;
short portindex = 0;
char HEADER ='H';

void setup()
{
    size(200,200);
    println(Serial.list());

    String portName = Serial.list()[portindex];
    myPort = new Serial(this,portName,9600);
    println("Conectando a->" + Serial.list()[portindex] );
    
    Date now=new Date();
    fileName =fnameFormat.format(now);
    output = createWriter(fileName + ".txt");
}

void draw()
{
    int val;
    String time;
    if(myPort.available() >= 15)
    {
        if(myPort.read() == HEADER)
        {
            String timeString = timeFormat.format(new Date());
            
            println("Recibi mensaje en el tiempo "+timeString);
            output.println(timeString);

            val = readArduinoInt();
            for(int pin=2, bit =1 ; pin <= 13 ; ++pin)
            {
                print("pin digital No. "+pin+" =");
                int isSet = (val & bit);
                if(isSet == 0 )
                {
                    println("0");
                    output.println("0");
                }
                else
                {
                    println("1");    
                    output.println("1");
                }
                bit = bit*2;
            }
                        
            for(int i=0;i<6;++i)
            {
                val = readArduinoInt();
                println("puerto analogico " +i+ " = " + val);           
                output.println("puerto analogico " +i+ " = " + val);
            }
            println("...");
            output.println("...");
        }
    }
}

void keyPressed()
{
    output.flush();
    output.close();
    exit();
}


int readArduinoInt()
{
    int val;
    
    val = myPort.read();
    val = myPort.read();
    return val;
}
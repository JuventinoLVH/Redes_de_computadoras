// Sketch de Processing para leer mensajes de puerto serie

import processing.serial.*;
Serial myPort;
char HEADER = 'H';
short LF =10;

//WARNING!
//Si es necesario cambie el valor de portIndex para ajustarlo al puerto usado pooor usted
// Linux: tty - 'blablablabla'
// Windows: comp - blabalablalbalalb
// MacOS: Idk - blabalblablba
// Plug and play es muy dificil, y ocupa conocimiento de sistemas operativos.
short portIndex=0;
// Super Warning


void setup()
{
    size(200,200);
    println(Serial.list());
    println("Conectandose a ->" + Serial.list()[portIndex]);
    myPort = new Serial(this, Serial.list()[portIndex], 9600);

}


void draw(){
}

void serialEvent(Serial p)
{
    String message = myPort.readStringUntil(LF);
    if(message != null )
    {
        print(message);
        String [] data = message.split(",");
        
        if( data[0].charAt(0) != HEADER && data.length > 3)
        {
            for( int i =1 ; i<data.length - 1 ; ++i)
            {
                println("valor" + i + " = "+ data[i] );
            }
            println();
        }
    }
}












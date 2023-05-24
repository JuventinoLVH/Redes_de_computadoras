/*
    rx -> tx
        Arduino MEGA tiene 4 puertos
        Arduino Uno tiene 1 puerto
    
    Que tal si queremos comunicar un arduino con varios otros? 
        Calendarizar -> Bloquear el puerto  cuando habla.
        
*/
#include <SoftwareSerial.h>

// 0 y 1 -> USB : Puerto Serie
const int rxpin=2; //recive
const int txpin=3; //envia
SofwareSerial serial_lcd(rxpin,txpin);

int numero=0;
void setup()
{
    Serial.begin(9600);
    serial_lcd.begin(9600); // puerto serie 'de software'
}

void loop()
{
    serial_lcd.print("El numero es: ");
    serial_lcd.print(numero);

    Serial.print("El numero es: ");
    Serial.print(numero);
    
    delay(500);
    number++;
}

const int LED_PIN=13;
int blinkRate=0;

void setup()
{
	Serial.begin(9600);
	pinMode(LED_PIN , OUTPUT);
    
}


void serialEvent()
{
    while(Serial.available())
    {
        char ch = Serial.read();
        Serial.write(ch);
        if( isDigit(ch))
        {
            blinkRate = (ch - '0'); // Valor ASCII convertido a numero
            blinkRate = blinkRate * 100; // La velocidad es fijada en 100 veces el digito recibido 
        }
    }
}


void loop()
{
	blink();
}


void blink()
{
    digitalWrite(LED_PIN,HIGH);
    delay(blinkRate);
    digitalWrite(LED_PIN,LOW);
    
}
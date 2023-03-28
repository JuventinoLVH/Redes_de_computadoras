const int LED_PIN=13;
int blinkRate=500;


void setup()
{
  Serial.begin(9600);
  pinMode(LED_PIN , LOW);

}


void loop()
{
  	randomSeed(analogRead(0)); //Se inicializa con basura
    int value1= random(10);
    int value2= random(100);
    int value3= random(1000);

    Serial.print('H'); // Cabecera del mensaje o 'marca de inicio'
    Serial.print(",");
    Serial.print(value1,DEC);
    Serial.print(",");
    Serial.print(value2,DEC);
    Serial.print(",");
    Serial.print(value3,DEC);
    Serial.print(",");
    Serial.println(); // Se inserta el caracter 'cr/if'
    blink();
}

void blink()
{
    digitalWrite(LED_PIN,HIGH);
    delay(blinkRate);
    digitalWrite(LED_PIN,LOW);
    delay(blinkRate);
}
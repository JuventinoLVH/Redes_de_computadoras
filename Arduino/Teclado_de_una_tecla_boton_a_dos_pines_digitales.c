/*
    Envia a puerto serie la tecla que fue presionada
    Para probarlo conectar un boton normalmente abierto a los pines digitales 7 y 5
*/

const int debounceTime=20;
const int rowPin=7;
const int colPin=5;

void setup()
{
    Serial.begin(9600);
    pinMode(rowPin,INPUT); //Pin de renglon como entrada
    pinMode(colPin,HIGH);  //Pin de columna como salida para ESCRIBIR
    digitalWrite(rowPin,HIGH) // Activa pull-ups
    digitalWrite(colPin,HIGH) // Desactiva la salida
}

void loop()
{
    char key = getKey();
    if(key != 0)
    {
        Serial.print("Leyo tecla ");
        Serial.println(key);
    }   
}

char getKey()
{
    char key=0;
    digitalWrite(colPin,LOW);

    if(digitalRead(row_pin) == LOW)
    {
        delay(debounceTime);
        while(digitalRead(rowPin) == LOW)
        {
            ;
        }
        key = '<';
    }
    digitalWrite(colPin,HIGH);
    return key;
}
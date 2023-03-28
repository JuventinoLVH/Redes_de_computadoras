/*
    Envia valores de pines digitales como datos binarios
    Sketch para correr en Arduino
*/

const char HEADER = 'H';

void setup()
{
    Serial.begin(9600);
    for(int i=2;i < 13;++i)
    {
        pinMode((i,INPUT);
        digitalWrite(i, HIGH);
    }
}

void loop()
{
    Serial.write(HEADER);
    
    int values = 0;
    int bite = 0;
    
    for(int i=2;i < 13;++i)
    {
        bitWrite(values, bit, digitalRead(i));
        bit = bit+1;
    }   

    sendBinary(values);
    for(int i=0 ; i <6;++i)
    {
        values = analogRead(i);
        SendBinary(values);
    }
    delay(1000);
}

void SendBinary(int values)
{
    Serial.write(lowByte(values);
    Serial.write(highByte(values);
}
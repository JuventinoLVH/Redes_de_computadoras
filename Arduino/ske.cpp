/*
    Sketch recibe_mensaje_con_multiples_campos_parse_Int
*/
const int NUMERO_DE_CAMPOS = 3;
int fieldIndex=0;
int valores[NUMERO_DE_CAMPOS];

void setup()
{
    Serial.begin(9600);

}

void loop()
{
    if(Serial.available())
    {
        for(fieldIndex=0;fieldIndex < 3; fieldIndex++)
        {
            valores[fieldIndex] = Serial.parseInt();
        }
        Serial.print(fieldIndex);
        Serial.println(" fields received");
        for(int i=0; i < fieldIndex ; ++i)
            Serial.println(valores[i]);
        fieldIndex = 0;
    }
}
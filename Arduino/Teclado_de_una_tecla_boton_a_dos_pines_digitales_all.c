const int rowPin[3]={4,5,6};
const int colPin[2]={12,13};
const int cantRow = 3;
const int cantCol = 2;
const int debounceTime=20;

void setup()
{
    Serial.begin(9600);

    //Pin de renglon como entrada
    for(int i=0;i < cantRow ; ++i )
    {
        pinMode(rowPin[i],INPUT);
        digitalWrite(rowPin[i],HIGH); // Activa pull-ups

    }

    //Pin de columna como salida para ESCRIBIR
    for(int i=0;i < cantCol ; ++i )
    {
        pinMode(colPin[i],OUTPUT);
        digitalWrite(colPin[i],HIGH);  // Desactiva la salida

    }
     
}

void loop()
{
    char key = getKey();
    if(key != ' ')
    {
        Serial.print("Leyo tecla ");
        Serial.println(key);
    }
}

char getKey()
{
    char key=' ';

    for(int i=0;i < cantCol ; ++i )
    {
        digitalWrite(colPin[i],LOW);
      
        for(int j=0;j < cantRow ; ++j )
        {
            if(digitalRead(rowPin[j]) == LOW)
            {
                delay(debounceTime);          	
                while(digitalRead(rowPin[j]) == LOW)
                {
                    ;
                }
              
                int indice = i*cantRow + j;
                key = int_to_char(indice);
            }

        }
      
        digitalWrite(colPin[i],HIGH);


    }

    return key;
}

char int_to_char(int n)
{
    switch (n)
    {
    case 0:
        return 'A';
        break;
    
    case 1:
        return 'B';
        break;

    case 2:
        return 'C';
        break;

    case 3:
        return 'D';
        break;

    case 4:
        return 'E';
        break;

    case 5:
        return 'F';
        break;

    case 6:
        return 'G';
        break;
    }

    return ' ';
}
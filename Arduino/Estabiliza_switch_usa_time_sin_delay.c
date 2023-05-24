const int ledPin=13;
const int inPin=2;
const int debounceTime = 20;

const int fastIncrement = 1000;
const int veryFastIncrement = 4000;

int count = 0;
void setup()
{
    pinMode(inPin,INPUT);
    digitalWrite(inPin,HIGH);
    pinMode(ledPin,OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    int duration = switchTime();
    if(duration > veryFastIncrement)
    {
        count += 1;
    }
    else
    {
        if(duration > fastIncrement)
        {
            count += 4;
        }
        else
        {
            if(duration > debounceTime)
            {
                count +=1;
            }
            else
            {
                // El switch no se presiono
                if(count == 0 )
                {
                    digitalWrite(ledPin,HIGH); 
                }
                else
                {
                    digitalWrite(ledPin,LOW);
                    count = count-1;
                }
            }
            
        }
    }
    Serial.println(count);
    delay(100);
}

long switchTime()
{
    static unsigned long startTime = 0;
    
    static boolean state;
    if(digitalRead(inPin) != state)
    {
        state = !state;
        startTime = millis();
    }

    if(state == LOW)
    {
        return millis() - startTime;
    }
    else
    {
        return 0;
    }

}
    /*
        Recibe 
        Sketch para Arduino
    */

    const char HEADER = 'H';
    const char MOUSE_TAG = 'M';
    const int TOTAL_BYTES=6;

    void setup()
    {
        Serial.begin(9600);
    }

    void loop()
    {
        if(Serial.available() >= TOTAL_BYTES)
        {
            if(Serial.read() == HEADER)
            {
                char tag = Serial.read();
                if(tag == MOUSE_TAG)
                {
                    //Primero leemos el HIGHBYTE y despues el LOWBYTE
                    int x = Serial.read() * 256;
                    x = x + Serial.read();
                    int y = Serial.read() * 256;
                    y = y + Serial.read();

                    Serial.print("Recibir mensaje de mouse, x= ");
                    Serial.print(x);
                    Serial.print(",y= ");
                    Serial.println(y);
                }
                else
                {
                    Serial.println("Recibe mensaje de desconocido");
                    Serial.write(tag);
                }
            }
        }
    }
// C++ code
//
const int PIN_BANDERA = 13;
const int BLINK_DELAY = 2000;
const int LEDS_INDICES[] = {2,3,4,5,6,7,8,9,10,11,12,14,15,16,17,18}; //El indice 0 es el bite con menos significancia
const int NUMERO_PINES = 16;

char buffer_entrada[6];
int index_buffer = 0;
int int_en_buffer = 0;
bool es_negativo = false;



void setup()
{
  pinMode(PIN_BANDERA, OUTPUT); 
  digitalWrite(PIN_BANDERA, HIGH );

  for(int i = 0 ; i<NUMERO_PINES ; ++i)
  {   
    pinMode(LEDS_INDICES[i], OUTPUT);
  }
  Serial.begin(9600);
}


void loop()
{
  if(Serial.available() )
  {

  	char ch = Serial.read();
    if( (ch == '-' && !es_negativo) || index_buffer < 5 && isDigit(ch) )
    {
    	buffer_entrada[index_buffer++] = ch; 
    }
    else // El buffer esta lleno o se leyo un caracter que no es digito
    {
    	Presentar_numero();
    }
  }
  
}

void Presentar_numero()
{
  buffer_entrada[index_buffer] = 0;
  int_en_buffer = atoi(buffer_entrada);
  Serial.print("El siguiente entero en el puerto serie es: ");
  Serial.println(int_en_buffer)	;
  Serial.println("Su representacion en binario es: ");
  Display_numero_protoboard();
  
  index_buffer = 0;
  es_negativo = false;
  Bandera_esperar();  


}

void Display_numero_protoboard()
{
  int count = 0;
  bool bit;
  //Recordatorio, entre menor sea el indice menor la importancia
  for(int i=15; i >= 0; --i)
  {
    
    bit = bitRead(int_en_buffer,i);
    Serial.print(bit);

    if(bit == true)
    {
      ++count;
      digitalWrite(LEDS_INDICES[i], HIGH );
    }
    else
    {
      digitalWrite(LEDS_INDICES[i], LOW);
    }
    if(i%4 == 0)
    {
      Serial.print(' ');
    }
  }
  Serial.println();

  Serial.print("La cantidad de '1''s en el numero es de: ");
  Serial.println(count);
  Serial.println("Su representacion esta en el protoboard");
  
}

void Bandera_esperar()
{
  digitalWrite(PIN_BANDERA,LOW);
  delay(BLINK_DELAY);
  digitalWrite(PIN_BANDERA,HIGH);
}
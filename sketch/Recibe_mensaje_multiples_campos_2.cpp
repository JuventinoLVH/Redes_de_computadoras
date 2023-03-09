/*
    Formato : H,<numero>,<numero>,<numero>,F
    espera un mensaje con el fomato: H,12,112,143,F
    Requiere el caracter de salto de linea para indicar el fin del mensaje  
    Para probarlo se requiere del Monitor de puerto Serie debidamente configurado
*/

const int NUMBER_OF_FIELDS =3;
int field_index = 0;
int values[NUMBER_OF_FIELDS];
bool leyendo_mensaje = false;
bool leyo_numero = false;
bool H_inmediatamente_anterior = false;


void setup()
{
    Serial.begin(9600);

}

void Devolver_estado_inicial()
{
    leyendo_mensaje = false;
    leyo_numero = false;
    H_inmediatamente_anterior = false;
    field_index = 0;
    for(int i=0 ; i<field_index ; ++i)
        values[i]=0;

}
void Procesar_basura()
{
    Serial.println("Basura");
    Devolver_estado_inicial();
}

void loop()
{
    if(Serial.available())
    {
        char ch =Serial.read();
        if(ch >= '0' && ch <= '9')
        {
            //Leyendo numero
            if (leyendo_mensaje && field_index < 4)
                leyo_numero = true;
                if(field_index < NUMBER_OF_FIELDS)
                {
                        values[field_index] = values[field_index] *10 + (ch - '0');
                }
            else 
                Procesar_basura();
            H_inmediatamente_anterior = false;
        }
        else
        {
            switch(ch)
            {
            case ',':
                if(leyo_numero && (leyendo_mensaje || H_inmediatamente_anterior)  && field_index < 4 )
                {
                    ++field_index;
                    H_inmediatamente_anterior = false;
                }
                else
                    Procesar_basura();
                break;


            case 'H':
                if(!leyendo_mensaje)
                {
                    leyendo_mensaje = true;
                    H_inmediatamente_anterior = true;
                }
                else
                    Procesar_basura();
                break;


            case 'F':
                if(leyendo_mensaje && field_index == 4 && !leyo_numero)
                {
                    for(int i=0; i<min(NUMBER_OF_FIELDS,field_index+1);++i)
                        Serial.println(values[i]);
    
                    Devolver_estado_inicial();
                }
                else
                    Procesar_basura();
                break;
            
            default:
                Procesar_basura();
                break;
            }
        }
}

















/*
    espera un mensaje con el fomato 12,112,143
    Requiere el caracter de salto de linea para indicar el fin del mensaje  
    Para probarlo se requiere del Monitor de puerto Serie debidamente configurado
*/
#define _TRANCISION(estado , accion ) ( matriz_trancision[estado][accion])
const int matriz_trancision[12][5] = { 
// H  D  ,  F  *
  {1 ,11,11,11,11},  // 0
  {11,10,2 ,10,10},  // 1  
  {10,3 ,10,10,10},  // 2
  {10,3 ,4 ,10,10},  // 3
  {10,5 ,10,10,10},  // 4
  {10,5 ,6 ,10,10},  // 5
  {10,7 ,10,10,10},  // 6
  {10,7 ,8 ,10,10},  // 7
  {10,10,10,9 ,10},  // 8
  {9 ,9 ,9 ,9 ,9 },  // 9
  {10,10,10,10,10},  // 10
  {11,11,11,11,11}   // 11
};


//--------------------------------------------------------------
//------------------- Variables de control ---------------------
//--------------------------------------------------------------
int values[3];
int estado_actual;
char look_ahead;



//--------------------------------------------------------------
//----------------- Declaracion de funciones -------------------
//--------------------------------------------------------------

//______________________________________________________________
/* Funcion que determina que hacer segun que estado
    \param estado El estado a procesar
*/
void Procesar_estado( int estado);
//---------------------------------------------------------------


//______________________________________________________________
/*  Maneja las acciones del estado 'Error'
*/
void Error();
//---------------------------------------------------------------


//______________________________________________________________
/* Maneja las acciones del estado 'Ignorar'
*/
void Ignorar();
//---------------------------------------------------------------


//______________________________________________________________
/* Reinicia todos los valores del automata.
*/
void Reiniciar();
//---------------------------------------------------------------


//______________________________________________________________
/* Mapea los caracteres a su columna correspondiente
    \param ch Caracter a mapear
    \return Columna correspondiente a ch en la tabla de 
        transiciones. 
*/
int Hasineito_improvisado(char ch);
//---------------------------------------------------------------



//--------------------------------------------------------------
//--------------------- Logica del arduino ---------------------
//--------------------------------------------------------------
void setup()
{
    Serial.begin(9600);

}


void loop()
{
    if(Serial.available())
    {
        look_ahead =Serial.peek();
        estado_actual = _TRANCISION(estado_actual,Hasineito_improvisado(look_ahead));
        Procesar_estado(estado_actual);
    }
}


//--------------------------------------------------------------
//---------------- Implementacion de funciones -----------------
//--------------------------------------------------------------
//______________________________________________________________
void Error()
{
    Serial.println("Mensaje Corrupto ... ");
    Reiniciar();
}
//---------------------------------------------------------------


//______________________________________________________________
void Ignorar()
{
    Serial.println("Basura...");
    estado_actual = 0;
}
//---------------------------------------------------------------


//______________________________________________________________
void Reiniciar()
{
    estado_actual = 0;
    values[0] = 0;
    values[1] = 0;
    values[2] = 0;
}
//---------------------------------------------------------------


//______________________________________________________________
int Hasineito_improvisado(char ch)
{
    int columna;
    
    switch (ch)
    {
    case 'H':
        columna = 0;
        break;

    case ',':
        columna = 2;
        break;

    case 'F':
        columna = 3;
        break;

    default:
        columna = 4;
        break;
    }
    if(ch >= '0' && ch <= '9')
        columna = 1;

    return columna;
}
//---------------------------------------------------------------


//______________________________________________________________
void Procesar_estado(int estado)
{
    char ch;
    switch (estado)
    {
    case 0: // Estado inicial
        break;
    case 1: 
        Serial.read();
        break;

    case 2: 
        Serial.read();
        break;
    case 3:
        ch = Serial.read();
        values[0] = values[0]*10 + ch - '0' ;
        break;

    case 4: 
        Serial.read();
        break;
    case 5:
        ch = Serial.read();
        values[1] = values[1]*10 + ch - '0' ;
        break;

    case 6: 
        Serial.read();
        break;
    case 7: 
        ch = Serial.read();
        values[2] = values[2]*10 + ch - '0' ;
        break;

    case 8: 
        Serial.read();
        break;
    case 9: 
        Serial.read();
        
        Serial.print("Llego un nuevo mensaje!! \n1: ");
        Serial.println(values[0]);
        Serial.print("2: ");
        Serial.println(values[1]);
        Serial.print("3: ");
        Serial.println(values[2]);
        Reiniciar();
        break;

    case 10: 
        Error();
        break;
    case 11: 
        Ignorar();
        ch = Serial.peek();
        if(ch != 'H')
            Serial.read();
        break;

    default:
        Serial.println("Algo muy muy muy muy inesperado paso ... ");
        break;
    }
}
//---------------------------------------------------------------
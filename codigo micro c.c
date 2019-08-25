#define EB   PORTA.RA3    // limite de agua medio.
#define BOM  PORTB.RB4    // bomba de agua.
#define EBOB PORTA.RA2    // sensor de precencia de agua.
#define BOB  PORTB.RB5    // bobina o resistencia de accion que evaporiza el agua.
#define T1   PORTA.RA1    // opcion de accion 1 actua cada 10 min
#define T2   PORTA.RA0    // opcion de accion 2 actua cada 15 min
#define T3   PORTA.RA7    // opcion de accion 3 actua cada 30 min
#define T4   PORTA.RA6    // opcion de accion 4 actua cada hora.
#define SF   PORTA.RA4    // sensor de precencia de agua.

void main() {
    TRISA = 1;
    TRISB = 0;


    while (1)
 {
 // CONTROL DE LA BOMBA.
   if (EB == 0 && SF == 1)// si el tanque esta bacio y se detecta agua por la bomba.
   {
    BOM = 1;   // la boba se activa
   }
   else
   {
    BOM = 0;
   }



       if(T1 == 1 )   // BOBINA DE VAPORIZADOR   ciclo 10 min.
      {
        if (EBOB = 1)  // si hay agua en el tanque
      {
        for(int c = 0;  c <= 30; c++)
       {
        BOB = 1;
        delay_ms(1000);                 // se activa durante 1 min cada 10 min
       }
       for( int c = 0; c <= 600; c++)
       {
        BOB = 0;
        delay_ms(1000);
       }
      }
     }
    else if(T2 == 1)   // BOBINA DE VAPORIZADOR   ciclo 15 min.
    {
     if (EBOB == 1)
     {
         for(int c = 0; c <= 30; c++)
       {
        BOB = 1;                // se activa durante 1 min cada 15 min
        delay_ms(1000);
       }
         for(int c = 0; c <= 900; c++)
       {
        BOB = 0;
        delay_ms(1000);
       }
      }
     }
    if-else(T3 == 1)   // BOBINA DE VAPORIZADOR   ciclo 30 min.
    {
      if (EBOB == 1)
      {
        for(int f = 0; f <= 30; f++)
        {
        BOB = 1;                      // se activa durante 1 min cada 30 min
        delay_ms(1000);
        }
        for(int f = 0; f <= 1800; f++)
        {
        BOB = 0;
        delay_ms(1000);
        }
       }
      }
    if-else(T4 == 1)   // BOBINA DE VAPORIZADOR   ciclo 1 hrs.
    {
      if (EBOB == 1)
      {
         for(int w = 0; w <= 30; w++)
       {
        BOB = 1;                      // se activa durante 1 min cada hora.
        delay_ms(1000);
       }
       for(int w = 0; w <= 3600; w++)
       {
        BOB = 0;
        delay_ms(1000);
        }
       }
      }
      else
      {
        BOB = 0;          // si no hay agua en el tanque no hace ninguna accion.
      }
}
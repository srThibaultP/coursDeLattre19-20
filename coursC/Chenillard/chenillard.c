#include <xc.h>
// Directives
#pragma config FOSC = HS // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF // Watchdog Timer Disable bit

#define _XTAL_FREQ 4000000
// Fonction initialisation des entrées et sorties
void init(void)
{
   TRISD = 0; // A compléter : configuration de la broche RD0 en sortie
   TRISB0 = 1;
   TRISC0 = 1;
   PORTD = 0;
}

void main()
{
init(); // Appel de la fonction initialisation des entrées sorties
   while(1)
   {
   
      if(RB0 == 0)
   {
   // A compléter
   RD0 = 1; // Allumer la led
   __delay_ms(1000); // Temporisation de 1000 ms ( 1 s)
   RD0 = 0;// Eteindre la led
      
         RD1 = 1; // Allumer la led
   __delay_ms(1000); // Temporisation de 1000 ms ( 1 s)
   RD1 = 0;// Eteindre la led
      
         RD2 = 1; // Allumer la led
   __delay_ms(1000); // Temporisation de 1000 ms ( 1 s)
   RD2 = 0;// Eteindre la led
      
         RD3 = 1; // Allumer la led
   __delay_ms(1000); // Temporisation de 1000 ms ( 1 s)
   RD3 = 0;// Eteindre la led
      
         RD4 = 1; // Allumer la led
   __delay_ms(1000); // Temporisation de 1000 ms ( 1 s)
   RD4 = 0;// Eteindre la led
      
         RD5 = 1; // Allumer la led
   __delay_ms(1000); // Temporisation de 1000 ms ( 1 s)
   RD5 = 0;// Eteindre la led
      
         RD6 = 1; // Allumer la led
   __delay_ms(1000); // Temporisation de 1000 ms ( 1 s)
   RD6 = 0;// Eteindre la led
      
         RD7 = 1; // Allumer la led
   __delay_ms(1000); // Temporisation de 1000 ms ( 1 s)
   RD7 = 0;// Eteindre la led
      
   }
}
}

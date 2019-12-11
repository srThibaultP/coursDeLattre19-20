#include <xc.h>
#include <stdio.h>  
#include <stdlib.h>

// CONFIG1
#pragma config FOSC = XT    // Oscillator Selection Bits (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = ON      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = OFF      // MCLR Pin Function Select (MCLR/VPP pin function is digital input)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable (Brown-out Reset disabled)
#define _XTAL_FREQ 4000000

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)

extern unsigned char TempLSB, TempMSB = 0;
void init(void);
void init_serie(void); 
void Init_Spi(void) ;
void lecture_spi(unsigned char );

void main(void)
{
 
    init();  // initialisation E/S
    init_serie();
    Init_Spi(); 

    while(1)
    {
             
        // Lecture température du capteur TC77 : appel de la fonction lecture_spi(......);
        ...............;	
        // Affichage sur Terminal    : appel de la fonction  printf(.................);
        ...............;
         // Temporisation d'une seconde 
       __delay_ms(1000);    

   }
}

void init(void)
{
		ANSEL=0X00;
        ANSELH=0;
        TRISA0=1;
        ANS0=1;
        TRISC=0b00010000;
        TRISD0=0;       
}

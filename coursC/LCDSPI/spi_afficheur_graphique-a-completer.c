
#include <xc.h>
#include "Nokia_5110.h"
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

unsigned char temperature=0,centaine=0,dizaine=0,unite=0;
float  resultat=0,resultat_1=0;
char s[20];
void init(void);
void init_a2d();
voidinit_serie();
unsigned int read_a2d(unsigned char);
void main(void)
{
 
    init();  // initialisation E/S
    init_a2d();
    init_serie();
    LcdInitialise() ; 
    
    
    __delay_us(100);
         
    while(1)
    {
       // A compléter 
      
     
     
       __delay_ms(1000);
    }

}


void init(void)
{
	
	    ANSEL=0X00;
        ANSELH=0;
        TRISA0=1;
        ANS0=1;
        TRISC=0;
        PORTC=0;
        
       
}

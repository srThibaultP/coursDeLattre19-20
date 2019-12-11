#include <xc.h>

#define _XTAL_FREQ 4000000

#define nokia_SCLK  RC3
#define nokia_SDO   RC5
unsigned char TempLSB, TempMSB = 0;

void Init_Spi(void) 
{

// Programmation de la liaison série synchrone
//SSPSTAT =0b01000000;  /* données délivrées sur front descendant. Seul le bit 6 intervient
    //        |_______ données transmise sur front descendant, avec CKP = 0 / erreur fig 9.1 doc*/
 SSPSTAT =0b01000000;          
SSPCON = 0b00100000; /*
                      ||||||||_ SPI maître, horloge de transmission Fosc/4 = 4MHz
           ||||_____ CKP = 0, état attente horloge 0
           |||______ validation de liaison série
           ||_______ sans importance pour l'utilisation présente */

} // fin Init_Spi()


void lecture_spi(unsigned char donnee)
{    
                  
        RD0=0;  // Sélection TC77
        __delay_us(100);
      
        SSPBUF = donnee; // Envoi Octet 1 
        while (SSPIF==0); // Attente de la fin de la transmission
       	SSPIF = 0; 	
		TempMSB =SSPBUF ;   // Lecture octet poids fort 
   
		SSPBUF =  donnee;  // Envoi Octet 2 
        while (SSPIF==0);  // Attente de la fin de la transmission
        SSPIF = 0; 
        TempLSB = SSPBUF ;   // Lecture octet poids faible 
        
		RD0=1;
       
       	
} 

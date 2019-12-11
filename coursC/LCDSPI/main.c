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

unsigned char TempLSB, TempMSB = 0;
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
        lecture_spi(0xAA);
        // Affichage sur Terminal    : appel de la fonction  printf(.................);
        printf("T=%.2f\r\n",((TempMSB<<8 | TempLSB)>>3)*0.0625);
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


//spi
#include <xc.h>

#define _XTAL_FREQ 4000000

#define nokia_SCLK  RC3
#define nokia_SDO   RC5

void Init_Spi(void)
{

// Programmation de la liaison sÃ©rie synchrone
//SSPSTAT =0b01000000;  /* donnÃ©es dÃ©livrÃ©es sur front descendant. Seul le bit 6 intervient
    //        |_______ donnÃ©es transmise sur front descendant, avec CKP = 0 / erreur fig 9.1 doc*/
 SSPSTAT =0b01000000;
SSPCON = 0b00100000; /*
                      ||||||||_ SPI maÃ®tre, horloge de transmission Fosc/4 = 4MHz
           ||||_____ CKP = 0, Ã©tat attente horloge 0
           |||______ validation de liaison sÃ©rie
           ||_______ sans importance pour l'utilisation prÃ©sente */

} // fin Init_Spi()


void lecture_spi(unsigned char donnee)
{

        RD0=0;  // SÃ©lection TC77
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


//rs232
#include <xc.h>
#define _XTAL_FREQ 4000000

void init_serie(void);
char getch(void);
void putch(char );


// Initialisation de la liaison série du PIC 16F887
void init_serie(void)
{
    SPBRG = 25;       // 9600 bauds pour un quartz de 4 MHz
    TXSTA = 0b00100100; //transmit enable, async, high speed mode
    RCSTA = 0b10000000; //serial port enable
    // Validation de l'émission et de la réception de la liaison série du PIC 16F887
    TXEN=1;
    BRGH=1;
    SPEN=1;
    CREN=1;
 }


// Ecriture d'un caractère
void putch(char data)
{
    while(!TRMT);  // Attente buffer vide
    TXREG = data;  // envoi caractère
}


// lecture d'un caractère
char getch()
{
    while(!RCIF);  // Attente arrivée caractère
    return RCREG;  // Renvoi du caractère reçu
}


#include <xc.h>
#include <stdio.h>
// BEGIN CONFIG
#pragma config FOSC = HS // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = ON// Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF // Flash Program Memory Code Protection bit (Code protection off)
//END CONFIG

#define _XTAL_FREQ 4000000

// prototypes des fonctions
void init_a2d(void);
void init_ES(void);
unsigned int read_a2d(unsigned char);

float  N=0,T=0;


void main()
{

        // Appel des fonctions initialisation des entr�es sorties et du CAN
	init_ES();
    init_a2d();
        // Boucle infinie

    while(1)
  	{
        N = read_a2d(0);  // Lecture de la valeur renvoy�e par le C.A.N
        T = N/2.046;	  // T en fonction De N
	    PORTD = T;
	    __delay_ms(100);

	}
}


void init_ES(void)
{
	TRISD=0x00; // Configuratio PORTD en sortie
    TRISA0=1;
    ANS0=1;
	TRISC6=0;
}


// Fonction initialisation du CAN
void init_a2d(void)
{
	ADCON0=0xC0;	// select Fosc/2
	ADCON1=0x80;	// select right justify result.
	ADON=1;		// turn on the A2D conversion module
}

// Fonction lecture r�sultat de la conversion analogique num�rique
// Valeur de N           choix de la voie

unsigned int read_a2d(unsigned char channel){
	channel&=0x0F;	// truncate channel to 4 bits
	ADCON0&=0xC3;	// clear current channel select
	ADCON0|=(channel<<2);	// apply the new channel select
    GO=1;	// initiate conversion on the selected channel
	while(GO)continue;
	return(256*ADRESH + ADRESL);	// return 8 MSB of the result
}

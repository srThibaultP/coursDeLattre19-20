
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
void putch(char c);
void init_serie(void);
char getch(void);
float T = 0, N=0;
char c=0;
char serialM;
//void getString(char * a, unsigned int b );

void main()
{

    // Appel des fonctions initialisation des entr�es sorties de la liaison s�rie et du CAN
	init_ES();
    init_serie();
    init_a2d();

     while(1)
  	{
			printf("Appuyez sur T pour afficher la temp%crature ou appuyez sur Q pour red%cmarrer\r\n ",130,130);
			serialM = getch();
			if(serialM == 't' || serialM == 'T'){
				N = read_a2d(0);  // Lecture de la valeur renvoy�e par le C.A.N
				T = N/2.046; // T en fonction De N
				printf("T = %.2f %cC\r\n", T,248);    // Envoi vers le Terminal de la valeur de la temp�rature
				__delay_ms(100);
			} else if (serialM == 'q' || serialM == 'Q') {
				break;
			}

	}
}



// Fonction initialisation des entr�es sorties

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
	ADCON1=0x80;	// select rightjustify result. A/D port configuration 0
	ADON=1;		// turn on the A2D conversion module
}

// Fonction lecture r�sultat de la conversion analogique num�rique
unsigned int read_a2d(unsigned char channel){
	channel&=0x0F;	// truncate channel to 4 bits
	ADCON0&=0xC3;	// clear current channel select
	ADCON0|=(channel<<2);	// apply the new channel select
    GO=1;	// initiate conversion on the selected channel
	while(GO)continue;
	return(256*ADRESH + ADRESL);	// return 8 MSB of the result
}

// Initialisation de la liaison s�rie du PIC 16F887
void init_serie(void)
{
    SPBRG = 25;       // 9600 bauds pour un quartz de 4 MHz
    TXSTA = 0b00100100; //transmit enable, async, high speed mode
    RCSTA = 0b10000000; //serial port enable
    // Validation de l'�mission et de la r�ception de la liaison s�rie du PIC 16F887
    TXEN=1;
    BRGH=1;
    SPEN=1;
    CREN=1;


}

// Ecriture d'un caract�re
void putch(char data)
{
    while(!TRMT);  // Attente buffer vide
    TXREG = data;  // envoi caract�re
}

// lecture d'un caract�re
char getch()
{
    while(!RCIF);  // Attente arriv�e caract�re
    return RCREG;  // Renvoi du caract�re re�u
}

// saisie d'une cha�ne de caract�res termin� par CR
void getString(char *input, unsigned int length)
{
    for(int i=0;i<length;i++)    // Lecture d'une cha�ne de cat�res de longueur length
    {
        input[i] = getch();        //acquire each character until lenght chars are received
        if(input[i]==13)  break;   //or if newline is received

    }

    printf("Il est : %.10s\r",input);                        //print input string
}

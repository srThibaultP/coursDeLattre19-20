#include <xc.h>
#include <stdio.h>
#include <stdlib.h>

#include "lcd.h";

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



// fonctions prototypes
void init_ES(void);
void init_a2d(void);
unsigned int read_a2d(unsigned char);
void EnvoyerChaine(unsigned char car[]);
void init_serie(void);
char getch(void);
void putch(char );

float temperature=0;
char s[20];
float i=0;

int main()
{
  init_ES();    // Initialisation des entrées et sorties : a compléter ci dessous
  Lcd_Init();   // Initialisation de l'afficheur LCD
  init_a2d();   // Initialisation C.A.N
  init_serie(); // Initialisation liason série

  __delay_ms(1000);

 printf("Affichage temperature\r\n");     // A compléter : Affichage sur Terminal
 Lcd_Clear();   // Effacer écran LCD
 Lcd_Set_Cursor(1,1);    // positionnement du curseur ligne 1, colonne 1

 while(1)
  {

    //Calcul Temperature
    temperature = read_a2d(2);
    temperature = temperature/2.046;  // A compléter : voir TPS précédents
	  printf("T = %.2f %cC\r\n", temperature,248);  // Affichage température sur Terminal

	// ----------------Affichage sur écran LCD  -------------------------------------------

    //sprintf(s, "T = %.2f %cC", temperature,223);    // sprintf  écrit dans le tableau s (de 20 caractères) les caractères contenus dans temperature
    //Lcd_Set_Cursor(1,1);        // positionnement du curseur du LCD sur ligne 1, colonne 1
    //Lcd_Write_String(s);        // Envoi de la chaîne de caractères représentant la température sur l'afficheur LCD

    // -------------------------------------------------------------------------------------

while (i != 10) {
  sprintf(s, "T = %.2f %cC", temperature,223);
  Lcd_Set_Cursor(1+i,1);
  Lcd_Write_String(s);
  i=+1;
  __delay_ms(1000);
}


  }
  return 0;
}


void init_ES(void)
{
	      TRISD = 1 ; // Configuration PORTD en sortie
        TRISA0=0;  // A complétér
        ANS0= 1;     // A complétér

        TRISC6=0;
 }

void init_a2d(void)
{
	ADCON0=0xC0;	// select Fosc/2
	ADCON1=0;	// select left justify result. A/D port configuration 0
        ADCON1=128;	// select right justify result. A/D port configuration 0
	ADON=1;		// turn on the A2D conversion module
}
// Temporisation logicielle


unsigned int read_a2d(unsigned char channel)
{
	//channel&=0x0F;	// truncate channel to 4 bits
	ADCON0&=0xC7;	// clear current channel select
	ADCON0|=(channel<<2);	// apply the new channel select
	GO=1;	// initiate conversion on the selected channel
	while(GO)continue;
	return(256*ADRESH + ADRESL);	// return 8 MSB of the result
}


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

// lecture d'un caractère
char getch()
{
    while(!RCIF);  // Attente arrivée caractère
    return RCREG;  // Renvoi du caractère reçu
}


// Ecriture d'un caractère
void putch(char data)
{
    while(!TRMT);  // Attente buffer vide
    TXREG = data;  // envoi caractère
}

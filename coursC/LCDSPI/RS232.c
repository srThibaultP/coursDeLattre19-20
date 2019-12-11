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
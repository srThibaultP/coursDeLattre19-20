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


void init_I2C(void);

void init_serie(void);
void putch(char data);
char getch(void);

//void ecrire_donnee_i2c(char adresse, char command,char donnee);
char lecture_donnee_i2c_DS1621(char adresse, char command);
void ecrire_command_i2c_DS1621(char adresse, char command);
void valid_I2C(void);

void ecrire_command_i2c_LCD(char adresse, char REG_COMMAND,char command);
void Cuseur_LCD_i2c_LCD(char adresse, char REG_COMMAND,char command,char Ligne, char Col);
void Ecrire_CAR_I2c_LCD(unsigned char adresse,char REG_COMMAND,char car);

int Temperature=20,Dizaine,Unite;

void main()

{
	init_I2C();   // Appel de la fonction initialisation des entrées sorties
      //  InitLCD();      // initialisation LCD
        init_serie();

        // Boucle infinie
        printf("Lecture temperature DS1621\r\n");
        while(1)
  	{
         //envoi commande Début de conversion température  à compléter
				 ecrire_command_i2c_DS1621(0x92,0xEE);
          //Lecture de la température à compléter
					Temperature=lecture_donnee_i2c_DS1621(0x92,0xAA);
	  // Affichage temperature sur Terminal à compléter
		printf("%d\r\n",Temperature );
		ecrire_command_i2c_LCD(0xC6,0,12);
		Dizaine=Temperature/10;
		Unite=Temperature%10;
		Ecrire_CAR_I2c_LCD(0xC6,0,'T');
		Ecrire_CAR_I2c_LCD(0xC6,0,'=');
		Ecrire_CAR_I2c_LCD(0xC6,0,Dizaine+48);
		Ecrire_CAR_I2c_LCD(0xC6,0,Unite+48);
		Ecrire_CAR_I2c_LCD(0xC6,0,'C');
	 __delay_ms(1000);

	}
}




void init_I2C(void)
{

    SSPCON = 0x28; // SSPEN = 1 + Master mode
	SSPADD = 24; // Fréquence 100KHz
	SSPSTATbits.SMP = 1; // slew rate ctrl disabled

}


void init_serie(void)
{
SPBRG=24; //emission 9600 bds
TXSTA=0xa4;
RCSTA=0x98;
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




void valid_I2C(void)
{
while(SSPSTATbits.R_W != 0);
while(SSPCON2bits.ACKSTAT != 0);
}

//void ecrire_donnee_i2c(0x90,0xAC,0x02);


void ecrire_command_i2c_DS1621(char adresse, char command)
{
SSPCON2bits.SEN = 1; //Start
while(SSPCON2bits.SEN!=0);
SSPBUF = adresse; //Adresse capteur
valid_I2C();
SSPBUF = command; //init du capteur
valid_I2C();
SSPCON2bits.PEN = 1; //Stop
while(SSPCON2bits.PEN!=0);
return ;
}


char lecture_donnee_i2c_DS1621(char adresse, char command)
{
char donnee = 0x00;
SSPCON2bits.SEN = 1;//Start
while(SSPCON2bits.SEN!=0);
SSPBUF = adresse; //Adresse du capteur en mode écriture
valid_I2C();
SSPBUF = command; //Commande de lecture
valid_I2C();
SSPCON2bits.PEN = 1;//Stop
while(SSPCON2bits.PEN!=0);
SSPCON2bits.SEN = 1;//Start
while(SSPCON2bits.SEN!=0);
SSPBUF = adresse+1;//Adresse du capteur en mode lecture
valid_I2C();
SSPCON2bits.RCEN = 1;//Attente réception
while(SSPCON2bits.RCEN!=0);
donnee = SSPBUF;//lecture buffer de réception
valid_I2C();
SSPCON2bits.PEN = 1;//Stop
while(SSPCON2bits.PEN!=0);
return(donnee);
}

void ecrire_command_i2c_LCD(char adresse, char REG_COMMAND,char command)
{
SSPCON2bits.SEN = 1; //Start
while(SSPCON2bits.SEN!=0);
SSPBUF = adresse; //Adresse
valid_I2C();

SSPBUF =REG_COMMAND;
valid_I2C();

SSPBUF = command;
valid_I2C();

SSPCON2bits.PEN = 1; //Stop
while(SSPCON2bits.PEN!=0);
return ;
}

void Cuseur_LCD_i2c_LCD(char adresse, char REG_COMMAND,char command,char Ligne, char Col)
{
SSPCON2bits.SEN = 1; //Start
while(SSPCON2bits.SEN!=0);
SSPBUF = adresse; //Adresse
valid_I2C();

SSPBUF =REG_COMMAND;
valid_I2C();

SSPBUF = command;
valid_I2C();


SSPBUF =Ligne;
valid_I2C();

SSPBUF =Col;
valid_I2C();


SSPCON2bits.PEN = 1; //Stop
while(SSPCON2bits.PEN!=0);
return ;
}

void Ecrire_CAR_I2c_LCD(unsigned char adresse,char REG_COMMAND,char car)
{
SSPCON2bits.SEN = 1; //Start
while(SSPCON2bits.SEN!=0);
SSPBUF = adresse; //Adresse
valid_I2C();

SSPBUF =REG_COMMAND;
valid_I2C();

SSPBUF = car;
valid_I2C();

SSPCON2bits.PEN = 1; //Stop
while(SSPCON2bits.PEN!=0);
return ;
}

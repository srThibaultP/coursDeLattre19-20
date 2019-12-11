#include <xc.h>

void init_a2d(void)
{
	ADCON0=0xC0;	// select Fosc/2
	ADCON1=0x80;	// select rightjustify result. A/D port configuration 0
	ADON=1;		// turn on the A2D conversion module
}

// Fonction lecture résultat de la conversion analogique numérique
unsigned int read_a2d(unsigned char channel)
{
	channel&=0x0F;	// truncate channel to 4 bits
	ADCON0&=0xC7;	// clear current channel select
	ADCON0|=(channel<<2);	// apply the new channel select
        //ADCON1=0x80;
	GO=1;	// initiate conversion on the selected channel
	while(GO)continue;
	return(256*ADRESH + ADRESL);	// return 8 MSB of the result
}

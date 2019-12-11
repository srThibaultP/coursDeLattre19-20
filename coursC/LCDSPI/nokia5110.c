// LCD nokia 5110 sur PORT C
/ LCD nokia 5110 sur PORT C
#include <xc.h>
#define nokia_CS    RC0
#define nokia_DC    RC2
#define nokia_RESet RC1
#define nokia_SCLK  RC3
#define nokia_SDO   RC5
#define _XTAL_FREQ 4000000
static unsigned int   LcdPos = 0;
unsigned short newline=0;
int ddram;
unsigned int charsel,char_row,charpos,chardata,plot_value;
unsigned long plot_value32,plot_llsb,plot_ulsb,plot_lmsb,plot_umsb;          
unsigned char  LcdCache[64];

//Table 5x7   96 rows * 5 bytes= 480 bytes
// modif 22-02-2014 was 2 tables de 240 bytes
const char TABLE_car[485]=
                 {0x00,0x00,0x00,0x00,0x00,   // 20 space  ASCII table for NOKIA
                  0x00,0x00,0x5f,0x00,0x00,   // 21 !
                  0x00,0x07,0x00,0x07,0x00,   // 22 "
                  0x14,0x7f,0x14,0x7f,0x14,   // 23 #
                  0x24,0x2a,0x7f,0x2a,0x12,   // 24 $
                  0x23,0x13,0x08,0x64,0x62,   // 25 %
                  0x36,0x49,0x55,0x22,0x50,   // 26 &
                  0x00,0x05,0x03,0x00,0x00,   // 27 '
                  0x00,0x1c,0x22,0x41,0x00,   // 28 (
                  0x00,0x41,0x22,0x1c,0x00,   // 29 )
                  0x14,0x08,0x3e,0x08,0x14,   // 2a *
                  0x08,0x08,0x3e,0x08,0x08,   // 2b +
                  0x00,0x50,0x30,0x00,0x00,   // 2c ,
                  0x08,0x08,0x08,0x08,0x08,   // 2d -
                  0x00,0x60,0x60,0x00,0x00,   // 2e .
                  0x20,0x10,0x08,0x04,0x02,   // 2f /
                  0x3e,0x51,0x49,0x45,0x3e,   // 30 0
                  0x00,0x42,0x7f,0x40,0x00,   // 31 1
                  0x42,0x61,0x51,0x49,0x46,   // 32 2
                  0x21,0x41,0x45,0x4b,0x31,   // 33 3
                  0x18,0x14,0x12,0x7f,0x10,   // 34 4
                  0x27,0x45,0x45,0x45,0x39,   // 35 5
                  0x3c,0x4a,0x49,0x49,0x30,   // 36 6
                  0x01,0x71,0x09,0x05,0x03,   // 37 7
                  0x36,0x49,0x49,0x49,0x36,   // 38 8
                  0x06,0x49,0x49,0x29,0x1e,   // 39 9
                  0x00,0x36,0x36,0x00,0x00,   // 3a :
                  0x00,0x56,0x36,0x00,0x00,   // 3b ;
                  0x08,0x14,0x22,0x41,0x00,   // 3c <
                  0x14,0x14,0x14,0x14,0x14,   // 3d =
                  0x00,0x41,0x22,0x14,0x08,   // 3e >
                  0x02,0x01,0x51,0x09,0x06,   // 3f ?
                  0x32,0x49,0x79,0x41,0x3e,   // 40 @
                  0x7e,0x11,0x11,0x11,0x7e,   // 41 A
                  0x7f,0x49,0x49,0x49,0x36,   // 42 B
                  0x3e,0x41,0x41,0x41,0x22,   // 43 C
                  0x7f,0x41,0x41,0x22,0x1c,   // 44 D
                  0x7f,0x49,0x49,0x49,0x41,   // 45 E
                  0x7f,0x09,0x09,0x09,0x01,   // 46 F
                  0x3e,0x41,0x49,0x49,0x7a,   // 47 G
                  0x7f,0x08,0x08,0x08,0x7f,   // 48 H
                  0x00,0x41,0x7f,0x41,0x00,   // 49 I
                  0x20,0x40,0x41,0x3f,0x01,   // 4a J
                  0x7f,0x08,0x14,0x22,0x41,   // 4b K
                  0x7f,0x40,0x40,0x40,0x40,   // 4c L
                  0x7f,0x02,0x0c,0x02,0x7f,   // 4d M
                  0x7f,0x04,0x08,0x10,0x7f,   // 4e N
                  0x3e,0x41,0x41,0x41,0x3e,   // 4f O

                  0x7f,0x09,0x09,0x09,0x06,   // 50 P
                  0x3e,0x41,0x51,0x21,0x5e,   // 51 Q
                  0x7f,0x09,0x19,0x29,0x46,   // 52 R
                  0x46,0x49,0x49,0x49,0x31,   // 53 S
                  0x01,0x01,0x7f,0x01,0x01,   // 54 T
                  0x3f,0x40,0x40,0x40,0x3f,   // 55 U
                  0x1f,0x20,0x40,0x20,0x1f,   // 56 V
                  0x3f,0x40,0x38,0x40,0x3f,   // 57 W
                  0x63,0x14,0x08,0x14,0x63,   // 58 X
                  0x07,0x08,0x70,0x08,0x07,   // 59 Y
                  0x61,0x51,0x49,0x45,0x43,   // 5a Z
                  0x00,0x7f,0x41,0x41,0x00,   // 5b [
                  0x02,0x04,0x08,0x10,0x20,   // 5c
                  0x00,0x41,0x41,0x7f,0x00,   // 5d
                  0x04,0x02,0x01,0x02,0x04,   // 5e
                  0x40,0x40,0x40,0x40,0x40,   // 5f
                  0x00,0x01,0x02,0x04,0x00,   // 60
                  0x20,0x54,0x54,0x54,0x78,   // 61 a
                  0x7f,0x48,0x44,0x44,0x38,   // 62 b
                  0x38,0x44,0x44,0x44,0x20,   // 63 c
                  0x38,0x44,0x44,0x48,0x7f,   // 64 d
                  0x38,0x54,0x54,0x54,0x18,   // 65 e
                  0x08,0x7e,0x09,0x01,0x02,   // 66 f
                  0x0c,0x52,0x52,0x52,0x3e,   // 67 g
                  0x7f,0x08,0x04,0x04,0x78,   // 68 h
                  0x00,0x44,0x7d,0x40,0x00,   // 69 i
                  0x20,0x40,0x44,0x3d,0x00,   // 6a j
                  0x7f,0x10,0x28,0x44,0x00,   // 6b k
                  0x00,0x41,0x7f,0x40,0x00,   // 6c l
                  0x7c,0x04,0x18,0x04,0x78,   // 6d m
                  0x7c,0x08,0x04,0x04,0x78,   // 6e n
                  0x38,0x44,0x44,0x44,0x38,   // 6f o
                  0x7c,0x14,0x14,0x14,0x08,   // 70 p
                  0x08,0x14,0x14,0x18,0x7c,   // 71 q
                  0x7c,0x08,0x04,0x04,0x08,   // 72 r
                  0x48,0x54,0x54,0x54,0x20,   // 73 s
                  0x04,0x3f,0x44,0x40,0x20,   // 74 t
                  0x3c,0x40,0x40,0x20,0x7c,   // 75 u
                  0x1c,0x20,0x40,0x20,0x1c,   // 76 v
                  0x3c,0x40,0x30,0x40,0x3c,   // 77 w
                  0x44,0x28,0x10,0x28,0x44,   // 78 x
                  0x0c,0x50,0x50,0x50,0x3c,   // 79 y
                  0x44,0x64,0x54,0x4c,0x44,   // 7a z
                  0x00,0x08,0x36,0x41,0x00,   // 7b
                  0x00,0x00,0x7f,0x00,0x00,   // 7c
                  0x00,0x41,0x36,0x08,0x00,   // 7d
                  0x10,0x08,0x08,0x10,0x08,   // 7e
                  0x78,0x46,0x41,0x46,0x78,   // 7f
                  0x00,0x06,0x09,0x09,0x06 // 7f Deg Symbol
};



void LcdInitialise(void) ; 
void    nokia_write_command(char nokia_cmd);
void    nokia_write_data(char nokia_data);
void    nokia_write_byte(char nokia_byte);
void    nokia_gotoxy(unsigned char Xnokia, unsigned char Ynokia);
void    nokia_erase_y(unsigned char Ynokia);
void    nokia_erase_x(unsigned char Xnokia);
void    nokia_printchar(unsigned char cvar, char Bold);
//void    nokia_printBigChiffre(unsigned char cvar ,char xB,char yB); // size 12x16
void    nokia_print_str(char *ptr,char Bold);         // size 5x7 ou 10x7
void    nokia_CLS(void);
void    nokia_write_data_inv(char nokia_data_inv);
void    nokia_clear_screen(void);
void    nokia_clear_xy(unsigned char Xnokia, unsigned char Ynokia);
void    nokia_print_uparrow(void);
void    nokia_print_downarrow(void);
void    nokia_print_leftarrow(void);
void    nokia_print_rightarrow(void);
void    nokia_print_degree(void);
void    nokia_print_lowbatdegree(void);

#ifdef With_Grafique
void    nokia_clean_ddram(void);
//Dot=0=bar Dot=1  plot_value8 <48
void    nokia_plot(unsigned char Xnokia,unsigned char plot_value8,unsigned char Dot); 
void    nokia_pixel(int pixelX,int pixelY,int pixelMode);
void    nokia_line(int x1,int y1,int x2,int y2,int lineMode);
void    nokia_rect(int x1,int y1,int x2,int y2,int rectMode);
void    nokia_circle(int centerX,int centerY,int radius,int circleMode);
void    nokia_redraw(void);
#endif



   
void LcdInitialise(void)  // derivee programme pour Arduino
{
  nokia_CS=0;//pinMode(PIN_SCE, OUTPUT);
  nokia_RESet=0;//pinMode(PIN_RESET, OUTPUT);
  nokia_DC=0;//pinMode(PIN_DC, OUTPUT);
  nokia_SDO=0;//pinMode(PIN_SDIN, OUTPUT);
  nokia_SCLK=0;//pinMode(PIN_SCLK, OUTPUT);
  nokia_RESet=0;    //digitalWrite(PIN_RESET, LOW);
  nokia_RESet=1;    //digitalWrite(PIN_RESET, HIGH);
  nokia_write_command(0x21);//LcdWrite(LCD_C, 0x21 );  // LCD Extended Commands.
  nokia_write_command(0xB1);//LcdWrite(LCD_C, 0xB1 );  // Set LCD Vop (Contrast). 
  nokia_write_command(0x04);//LcdWrite(LCD_C, 0x04 );  // Set Temp coefficent. //0x04
  nokia_write_command(0x14);//LcdWrite(LCD_C, 0x14 );  // LCD bias mode 1:48. //0x13
  nokia_write_command(0x0C);//LcdWrite(LCD_C, 0x0C );  // LCD in normal mode.
  nokia_write_command(0x20);//LcdWrite(LCD_C, 0x20 );
  nokia_write_command(0x0C);//LcdWrite(LCD_C, 0x0C );
}




void nokia_init(void)
{int i;
nokia_DC=1;
nokia_CS=0;
nokia_RESet=0;     // reset chip during > 100ms
__delay_ms(250);
nokia_CS=1;
nokia_RESet=1;
__delay_ms(200);
nokia_write_command(0x21);   // set extended instruction set
nokia_write_command(0xC2); //Contrast value 0xE0=Black  normal is 0x90 to 0xc2  LCD=3.06+162*0.06=4.02
nokia_write_command(0x04);   // temperature coeff
nokia_write_command(0x14);   //0x13   bias mode   1:48 
nokia_write_command(0x0C);
nokia_write_command(0x20);   // switch back to normal cde
__delay_ms(150);
nokia_write_command(0x0c);   // normal display,auto incr on X
__delay_ms(50);
#ifdef With_Grafique
for(i=0;i<640;i++)LcdCache[i]=0;
nokia_clean_ddram();
#endif
}

void nokia_bargraph_H(char Ligne,int Value)
{int v,Cpt1;
     nokia_erase_y(Ligne);
    if (Value==0) return;
    v= Value/12;        //  car 1024 points /84 pixels =12 points  par pixel
    for (Cpt1=0;Cpt1<v;Cpt1++)
    {
      nokia_gotoxy(Cpt1,Ligne);
      nokia_write_data(0b00111100);// Allume les pixels du centre
    }
 }



void nokia_write_command(char nokia_cmd)
{
nokia_DC=0;   // byte is a command it is read with the eight SCLK pulse
nokia_CS=0;   // chip enabled
__delay_us(25);
nokia_write_byte(nokia_cmd);
nokia_CS=1;   // chip disabled
}

void nokia_write_data(char nokia_data)
{
nokia_DC=1;
nokia_CS=0;   // chip enabled
__delay_us(25);
nokia_write_byte(nokia_data);
nokia_CS=1;   // chip disabled
}

void nokia_write_byte(char nokia_byte)    // serial write data or command
{
char caa;
for (caa=8;caa>0;caa--) {
      nokia_SCLK=0;
      __delay_us(10);
      if ((nokia_byte&0x80)==0){nokia_SDO=0;}
      else {nokia_SDO=1;}
      nokia_SCLK=1;
      nokia_byte= nokia_byte << 1;
      }
}

void nokia_gotoxy(unsigned char Xnokia, unsigned char Ynokia)  
{
  nokia_write_command(0x40|(Ynokia&0x07));   // Y axe initialisation: 0100 0yyy
  nokia_write_command(0x80|(Xnokia&0x7f));   // X axe initialisation: 1xxx xxxx
}

void nokia_erase_y(unsigned char Ynokia)
{
char row;
for(row=0;row<84;row=row+6)  // 84-6 sinon car un ' '=6 pixels sinon deborde ligne suivante
{
nokia_gotoxy(row,Ynokia);
__delay_us(10);
nokia_printchar(' ',0);
__delay_us(10);
}
nokia_gotoxy(0,Ynokia);
}

void nokia_CLS()
{int i;
  nokia_gotoxy(0,0);
  for (i=0;i<5;i++)
  {
    nokia_write_data(0x00);  nokia_write_data(0x00);
    nokia_write_data(0x00);  nokia_write_data(0x00);
    nokia_write_data(0x00);  nokia_write_data(0x00);
    nokia_write_data(0x00);  nokia_write_data(0x00);
    nokia_write_data(0x00);  nokia_write_data(0x00);
    nokia_write_data(0x00);  nokia_write_data(0x00);
    nokia_write_data(0x00);  nokia_write_data(0x00);
   }
  nokia_gotoxy(0,0);
}


void nokia_erase_x(unsigned char Xnokia)
{
char column;
for (column=0;column<8;column++){
      nokia_gotoxy(Xnokia,column);
      nokia_write_data(0x00);  nokia_write_data(0x00);
      nokia_write_data(0x00);  nokia_write_data(0x00);
      nokia_write_data(0x00);  nokia_write_data(0x00);
      nokia_write_data(0x00);  nokia_write_data(0x00);
       }
}

void nokia_printchar(unsigned char cvar,char Bold)        // Write 1 character to LCD
{
charsel=cvar;
if (charsel<0x0020)return;
if (charsel>0x007f)return;
for (char_row=0;char_row<5;char_row++)
  {    // 5 bytes largeur matrice caractere
   charpos=(charsel-0x0020)*5;
   chardata=TABLE_car[(charpos+char_row)];
   nokia_write_data(chardata);      // send data to nokia
   if(Bold>0) nokia_write_data((unsigned char)chardata);
 }
 nokia_write_data(0x00);      //    1 byte (always blank)
}


void nokia_write_data_inv(char nokia_data_inv)
{
char caa;
nokia_DC=1;
nokia_CS=0;   // chip enabled
for (caa=8;caa>0;caa--) {
      nokia_SCLK=0;
      __delay_us(10);
      if ((nokia_data_inv&0x01)==0){nokia_SDO=0;}
      else {nokia_SDO=1;}
      nokia_SCLK=1;
      nokia_data_inv=nokia_data_inv>>1;
         }
nokia_CS=1;   // chip disabled
}

void nokia_clear_screen(void)
{
nokia_erase_y(0);
nokia_erase_y(1);
nokia_erase_y(2);
nokia_erase_y(3);
nokia_erase_y(4);
nokia_erase_y(5);
nokia_erase_y(6);
nokia_erase_y(7);
}

void nokia_clear_xy(unsigned char Xnokia, unsigned char Ynokia)
{
nokia_gotoxy(Xnokia,Ynokia);
nokia_printchar(' ',0);
nokia_gotoxy(Xnokia,Ynokia);
}

void nokia_print_uparrow(void)
{
nokia_write_data(0x00);nokia_write_data(0x04);
nokia_write_data(0x02);nokia_write_data(0x7f);
nokia_write_data(0x02);nokia_write_data(0x04);
nokia_write_data(0x00);nokia_write_data(0x00);
}
//
void nokia_print_downarrow(void)
{
nokia_write_data(0x10);nokia_write_data(0x20);
nokia_write_data(0x7f);nokia_write_data(0x20);
nokia_write_data(0x10);nokia_write_data(0x00);
nokia_write_data(0x00);nokia_write_data(0x00);
}
//
void nokia_print_leftarrow(void)
{
nokia_write_data(0x08);nokia_write_data(0x1c);
nokia_write_data(0x2a);nokia_write_data(0x08);
nokia_write_data(0x08);nokia_write_data(0xf8);
nokia_write_data(0x00);nokia_write_data(0x00);
}
//
void nokia_print_rightarrow(void)
{
nokia_write_data(0x08);nokia_write_data(0x08);
nokia_write_data(0x2a);nokia_write_data(0x1c);
nokia_write_data(0x08);nokia_write_data(0x00);
nokia_write_data(0x00);nokia_write_data(0x00);
}
//
void nokia_print_degree(void)
{
nokia_write_data(0x00);nokia_write_data(0x06);
nokia_write_data(0x09);nokia_write_data(0x09);
nokia_write_data(0x06);nokia_write_data(0x00);
nokia_write_data(0x00);nokia_write_data(0x00);
}

void nokia_print_lowbatdegree(void)
{
nokia_write_data(0x00);nokia_write_data(0x06);
nokia_write_data(0x0f);nokia_write_data(0x0f);
nokia_write_data(0x06);nokia_write_data(0x00);
nokia_write_data(0x00);nokia_write_data(0x00);
}

//--------------------------------
void nokia_print_str(char *ptr,char Bold)
{
while(*ptr!=0){ 
      nokia_printchar(*ptr++,Bold);
      __delay_us(10);
    } ;
}

#ifdef With_Grafique
void nokia_pixel(int pixelX,int pixelY,int pixelMode)
{
	unsigned int index;
	int offset;
    if ( pixelX > 83 ) return;
    if ( pixelY > 47 ) return;
	index = ((pixelY / 8) * 84) + pixelX;
	offset= pixelY - ((pixelY / 8) * 8);
	if (pixelMode == 0) LcdCache[index] &= ~(0x01 << offset);  // and  eteint
	if (pixelMode == 1) LcdCache[index] |= (0x01 << offset);   // or   allume
	if (pixelMode == 2) LcdCache[index] ^= (0x01 << offset);   // xor  reverse
}

void nokia_line(int x1,int y1,
                int x2,int y2,
                int lineMode)
{
    int dx, dy, stepx, stepy, fraction;
    dy = y2 - y1;
    dx = x2 - x1;
    if ( dy < 0 )
    {
        dy    = -dy;
        stepy = -1;
    }
    else  stepy = 1;
    if ( dx < 0 )
    {
        dx    = -dx;
        stepx = -1;
    }
    else   stepx = 1;
    dx <<= 1;
    dy <<= 1;
    nokia_pixel( x1, y1, lineMode );
    if ( dx > dy )
    {
        fraction = dy - (dx >> 1);
        while ( x1 != x2 )
        {
            if ( fraction >= 0 )
            {
                y1 += stepy;
                fraction -= dx;
            }
            x1 += stepx;
            fraction += dy;
            nokia_pixel( x1, y1, lineMode );
        }
    }
    else
    {
        fraction = dx - (dy >> 1);
        while ( y1 != y2 )
        {
            if ( fraction >= 0 )
            {
                x1 += stepx;
                fraction -= dy;
            }
            y1 += stepy;
            fraction += dx;
            nokia_pixel( x1, y1, lineMode );
        }
    }
}

void nokia_redraw(void)
{
	unsigned int a;
    nokia_gotoxy(0,0);      // Se placer en 0,0
	LcdPos = 0;
    for (a=0;a<504;a++){nokia_write_data(LcdCache[a]);} // Affiche le bitmap
}

void nokia_rect(int x1,int y1,
                int x2,int y2,
                int rectMode)
{
	nokia_line(x1,y1,x2,y1,rectMode);
	nokia_line(x2,y1,x2,y2,rectMode);
	nokia_line(x2,y2,x1,y2,rectMode);
	nokia_line(x1,y2,x1,y1,rectMode);
	nokia_redraw();
}


void nokia_circle(int centerX,int centerY,
                  int radius,
                  int circleMode)
{
	signed int tswitch;
	int y, x = 0;
	int d;

	d = centerY - centerX;
	y = radius;
	tswitch = 3 - 2 * radius;
	while (x <= y)
		{
		nokia_pixel(centerX + x,centerY + y, circleMode);
		nokia_pixel(centerX + x,centerY - y, circleMode);
		nokia_pixel(centerX - x,centerY + y, circleMode);
		nokia_pixel(centerX - x,centerY - y, circleMode);
		nokia_pixel(centerY + y - d, centerY + x, circleMode);
		nokia_pixel(centerY + y - d, centerY - x, circleMode);
		nokia_pixel(centerY - y - d, centerY + x, circleMode);
		nokia_pixel(centerY - y - d, centerY - x, circleMode);

		if (tswitch < 0) tswitch += (4 * x + 6);
		else {
			tswitch += (4 * (x - y) + 10);
			y--;
		}
	x++;
	}
 nokia_redraw();
}


void nokia_clean_ddram(void)
{
 nokia_CS=0;
 nokia_gotoxy(0,0);         //   96*8=768   84*6=504    clear LCD
 for (ddram=0;ddram<504;ddram++)
 {
  nokia_write_data(0x00);
  LcdCache[ddram]=0;
  __delay_ms(1);
 }
}

// X value 0 à 83    Y value 0 à 47
void nokia_plot(unsigned char Xnokia,unsigned char plot_value8,unsigned char Dot)
{
char i;
plot_value32=0;
if(Dot==1)plot_value32|=1;         // unremark this if you want dotgraph instead of bargraph
for (i=0;i!=plot_value8;i++)
 {
 if(Dot==0) plot_value32|=1;         // remark this if you want dotgraph instead of bargraph
  plot_value32<<=1;
 }
plot_value32|=2;           // bottom line is always filled
plot_llsb=(plot_value32&0xff);
plot_ulsb=((plot_value32>>8)&0xff);
plot_lmsb=((plot_value32>>16)&0xff);
plot_umsb=((plot_value32>>24)&0xff);
nokia_gotoxy(Xnokia,1);
nokia_write_data_inv(plot_umsb);
nokia_gotoxy(Xnokia,2);
nokia_write_data_inv(plot_lmsb);
nokia_gotoxy(Xnokia,3);
nokia_write_data_inv(plot_ulsb);
nokia_gotoxy(Xnokia,4);
nokia_write_data_inv(plot_llsb);
}

#endif // With_Grafique

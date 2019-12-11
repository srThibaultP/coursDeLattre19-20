//rev fev 2014
// nokia LCD 5110 LPH7366-1 alim 3,6V via RA3  Pic en +5V
// R=1K en serie sur les commandes LCD
#define With_Grafique

// LCD nokia 5110 sur PORT C
#ifndef nokia_CS
#define nokia_CS    LATCbits.LATC0
#define nokia_DC    LATCbits.LATC1
#define nokia_RESet LATCbits.LATC2
#define nokia_SCLK  LATCbits.LATC3
#define nokia_SDA   LATCbits.LATC5
#define nokia_Power   LATAbits.LATA3
#endif

extern void LcdInitialise(void);  // derivee programme pour Arduino
extern void    nokia_init(void);
extern void     nokia_write_command(char nokia_cmd);
extern void    nokia_write_data(char nokia_data);
extern void    nokia_write_byte(char nokia_byte);
extern void   nokia_gotoxy(unsigned char Xnokia, unsigned char Ynokia);
extern void    nokia_erase_y(unsigned char Ynokia);
extern void    nokia_erase_x(unsigned char Xnokia);
extern void    nokia_printchar(unsigned char cvar, char Bold);
//void    nokia_printBigChiffre(unsigned char cvar ,char xB,char yB); // size 12x16
extern void    nokia_print_str(char *ptr,char Bold);         // size 5x7 ou 10x7
extern void    nokia_CLS(void);
extern void    nokia_write_data_inv(char nokia_data_inv);
extern void    nokia_clear_screen(void);
extern void    nokia_clear_xy(unsigned char Xnokia, unsigned char Ynokia);
extern void    nokia_print_uparrow(void);
extern void    nokia_print_downarrow(void);
extern void    nokia_print_leftarrow(void);
extern void    nokia_print_rightarrow(void);
extern void    nokia_print_degree(void);
extern void    nokia_print_lowbatdegree(void);
extern void    nokia_bargraph_H(char Ligne,int Value);

#ifdef With_Grafique
extern void    nokia_clean_ddram(void);
extern void    nokia_plot(unsigned char Xnokia,unsigned char plot_value8,unsigned char Dot);
extern void    nokia_pixel(int pixelX,int pixelY,int pixelMode);
extern void    nokia_line(int x1,int y1,int x2,int y2,int lineMode);
extern void     nokia_rect(int x1,int y1,int x2,int y2,int rectMode);
extern void     nokia_circle(int centerX,int centerY,int radius,int circleMode);
extern void     nokia_redraw(void);
#endif



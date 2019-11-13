
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


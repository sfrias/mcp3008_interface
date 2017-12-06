/**
Autor: Alfonso Soria Muñoz
Este código está bajo licencia Apache
**/

#include <wiringPi.h>
#include <wiringPiSPI.h>
#include "analogToDigital.h"




int analogRead(int canal)
{
    if(canal<0 || canal>7)
        return -1;
    unsigned char buffer[3] = {1};
    buffer[1] = (CHAN_CONFIG_SINGLE + canal) << 4;
    wiringPiSPIDataRW(0, buffer, 3);
    return ( (buffer[1] & 3 ) << 8 ) + buffer[2]; 
}

int analogWrite(int canal, int valor)
{
    /*Función no implementada de momento*/
    return -1;
}

int mcpSetup()
{                       
    if ((myFd = wiringPiSPISetup (CANAL0, 1000000)) < 0)//1000000 == Frecuencia del reloj
    {
        return -1;
    }

    return 0;
}

int mcpClose()
{
    close(myFd);
}
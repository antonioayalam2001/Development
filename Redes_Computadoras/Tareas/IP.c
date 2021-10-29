#include <stdio.h>


int main(int argc, char const *argv[])
{
unsigned char ip[4]	=  {0xE1,0x01,0x01,0x01};
                    // {0x0A,0xFA,0x01,0x01};	//Z	{10,250,1,1} 
                    // {0x96,0x0A,0x0F,0x00};	//Y {150,10,15,0}
                    // {0xE1,0x01,0x01,0x01};	//M {225,1,1,1}
					// {0xC0,0x0E,0x02,0x00};	// {192,14,2,0}
					// {0x94,0x11,0x09,0x01};	//W {148,17,9,1}
					// {0xC1,0x00,0x00,0xFF};	//V {193,0,0,255}
					// {0xDC,0xC8,0x17,0x01};	//U {220,200,23,1}
					// {0xB,0x64,0x12,0x04};	//T {177,100,18,4}
					// {0x5F,0x00,0x15,0x00};	//S {95,0,21,0}
					// {0x6F,0x6F,0x6F,0x6F};	//R {111,111,111,111}
					// {0xDB,0x1A,0x33,0x00};	//Q {219,26,51,0}
					// {0xA7,0x00,0x00,0x00};	//P {167,0,0,0}
					// {0xF0,0x01,0x01,0x01};	//O {240,1,1,1}
					// {0x0A,0x01,0x01,0x01};	//N {10,1,1,1}
unsigned char m[4]={0,0,0,0};
    if (ip[0] & 128)
    {
        if (ip[0] & 64)
        {
            if (ip[0] & 32)
            {
                if (ip[0] & 16)
                {
                    printf("La IP ingresada es de tipo E\n");
                }
                else
                {
                    printf("La IP ingresada es de tipo D \n");
                }
            }
            else
            {
                printf("La IP ingresada es de tipo C\n");
                m[0] = 255;
                m[1] = 255;
                m[2] = 255;
                printf("La direccion de tipo red es: %u.%u.%u.%u \n", (ip[0] & m[0]), (ip[1] & m[1]), (ip[2] & m[2]), (ip[3] & m[3]));
                printf("La direccion de tipo Broadcast es: %u.%u.%u.%u", (unsigned char)(ip[0] | (~m[0])), (unsigned char)(ip[1] | (~m[1])), (unsigned char)(ip[2] | (~m[2])), (unsigned char)(ip[3] | (~m[3])));
            }
        }
        else
        {
            printf("La IP ingresada es de tipo B\n");
            m[0] = 255;
            m[1] = 255;
            printf("La direccion de tipo red es: %d.%d.%d.%d \n", (ip[0] & m[0]), (ip[1] & m[1]), (ip[2] & m[2]), (ip[3] & m[3]));
            printf("La direccion de tipo Broadcast es: %d.%d.%d.%d", (unsigned char)(ip[0] | (~m[0])), (unsigned char)(ip[1] | (~m[1])), (unsigned char)(ip[2] | (~m[2])), (unsigned char)(ip[3] | (~m[3])));
            // Declarar los vlores de la mascara
        }
    }
    else
    {
        printf("La IP ingresada es de tipo A: \n");
        m[0] = 255;
        printf("La direccion de tipo red es: %d.%d.%d.%d \n", (ip[0] & m[0]), (ip[1] & m[1]), (ip[2] & m[2]), (ip[3] & m[3]));
        printf("La direccion de tipo Broadcast es: %d.%d.%d.%d", (unsigned char)(ip[0] | (~m[0])), (unsigned char)(ip[1] | (~m[1])), (unsigned char)(ip[2] | (~m[2])), (unsigned char)(ip[3] | (~m[3])));
    }
    return 0;
}
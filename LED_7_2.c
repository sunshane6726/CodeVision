#include <90can128.h>
#include <delay.h>

void main(void){
    unsigned char buff;
    unsigned char Led[8] = {0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f};
    int i;

    PORTA = 0X00;
    DDRA = 0XFF;

    while(1){

        buff = 0xfe;

        for(i=1; i<=8; i++)
        {
            PORTA = Led[i];


            delay_ms(300);

        }

        buff = 0x7f;

        for(i=1; i<=8; i++)
        {

            PORTA = Led[i];


            delay_ms(300);
        }


    }

}
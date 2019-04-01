#include <90can128.h>
#include <delay.h>

void main(void){

    unsigned char buff;
    int i;

    PORTA = 0XFF;
    DDRA = 0XFF;

    while(1){

        buff = 0xfe;

        for(i=1; i<=8; i++)
        {
            PORTA = buff;

            buff = (buff << 1) | 0x01;
            delay_ms(100);

        }

        buff = 0x7f;

        for(i=1; i<=8; i++)
        {

            PORTA = buff;

            buff= (buff >> 1) | 0x80;
            delay_ms(100);
        }


    }

}
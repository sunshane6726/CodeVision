#include <90can128.h>
#include <delay.h>

void main(void){

    unsigned char buff;

    PORTA = 0XFF;
    DDRA = 0XFF;

    PORTB = 0XFF;
    DDRB = 0XFF;

        while(1){

            buff = 0x01; // 초기값 00000001
            while(buff != 0x00) // 포트a 시프트

            {


            }


        }
}
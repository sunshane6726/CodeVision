#include <90can128.h>
#include <delay.h>

void main(void){

unsigned char buff;             // LED를 위해서 8비트를 저장

    PORTA = 0XFF;
    DDRA = 0XFF;

    PORTC = 0XFF;
    DDRC = 0X00;
            while(1){        // 무한 반복

                buff = PINC;             // portc로 입력논리 저장

                PORTA = buff; // LED 출력


            }

}
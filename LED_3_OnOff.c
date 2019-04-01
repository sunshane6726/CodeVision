#include <90can128.h>
#include <delay.h>


void main(void){
    PORTA = 0XFF;
    DDRA = 0XFF;

    PORTC = 0XFF;
    DDRC = 0X00;

            while(1){

                if(PINC.0 == 0)  // SW0 ON ?
                    PORTA = 0X00;       // LED 모두 점등

                else if(PINC.1 == 0)   // SW1 ON?

                     PORTA = 0XFF;  // LED 모두 OFF


            }

}
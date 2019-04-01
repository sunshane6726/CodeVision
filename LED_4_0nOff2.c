#include <90can128.h>
#include <delay.h>


void main(void){
    PORTA = 0XFF;
    DDRA = 0XFF;

    PORTC = 0XFF;
    DDRC = 0X00;

            while(1){

                if(PINC.0 == 0)  // SW0 ON  두개
                    PORTA = 0b00111111;       // LED 모두 점등

                else if(PINC.1 == 0)   // SW1 두개 점등

                     PORTA = 0B11001111;
                else if(PINC.2 == 0)

                    PORTA = 0b11110011;  // SW2 두개 점등
                else if(PINC.3 == 0);

                    PORTA = 0B11111100;  //SW3 두개 점등

            }

}
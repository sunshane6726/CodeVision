#include <90can128.h>
#include <delay.h>


void main(void){

    unsigned char keyin; // 키 입력 버퍼 변수

    PORTA = 0XFF;       // poat a 초기값
    DDRA = 0XFF;  // port a 출력으로


    PORTC = 0XFF; //port c 초기값
    DDRC = 0X00;   // port c 입력으로

            while(1){ //=========== 무한 반복 ====================

                keyin = PINC & 0xFF; // & 0000 1111

                switch(keyin){

                    case 0x0e:   // 0000 1100 -> sw0가 on인 경우

                        PORTA= 0B00111111;
                    break;
                    case 0x0d:   // 0000 1101-> sw1가 on인 경우
                        PORTA = 0B11001111;
                    break;
                    case 0x0b:     // 1110 0011-> sw2가 on 인 경우
                        PORTA = 0B11110011;
                    break;

                    case 0x07:   // 1111 1100 -> sw3가 on인 경우
                            PORTA = 0B11111100;

                    break;

                }

            }

}
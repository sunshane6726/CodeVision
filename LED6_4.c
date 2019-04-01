#include <90can128.h>
#include <delay.h>

void main(void){

    unsigned char buff;  //LED 점등 데이터 가 저장될 8BIT 변수 선언

    PORTA = 0XFF;  // PORT A 초기값
    DDRA = 0XFF; // PORT A 출력 값 으로 사용



    while(1){ //  =========== 무한 반복 ===============

        buff = 0xfe;      // 초기 점등데이터

        while(buff != 0xff)        // 변수값이 0xff가 아니라면 반복
        {
            PORTA = buff;          // 즉, buff값이 0xff 될때까지 반복
            delay_ms(300);

            buff <<= 1;      // 다음 점등 데이터 준비
            buff != 0x01;


        }

    }      // ---------------------------------


}
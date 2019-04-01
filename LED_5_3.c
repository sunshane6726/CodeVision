#include <90can128.h>
#include <delay.h>

void main(void){

    unsigned char buff;  //LED 점등 데이터 가 저장될 8BIT 변수 선언

    PORTA = 0XFF;  // PORT A 초기값
    DDRA = 0XFF; // PORT A 출력 값 으로 사용



    while(1){ //  =========== 무한 반복 ===============
        buff = 0XFF;  // 초기 점등데이터 저장 : BUFF <-- 0B11111110;

        while(buff != 0x00)
        {
            buff <<= 1;  //점등 데이터 준비
            PORTA = buff;  // LED 점등
            delay_ms(500);

        }

    }      // ---------------------------------


}
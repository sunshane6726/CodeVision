#include <90can128.h>
#include <delay.h>

void main(void){

    unsigned char buff;  //LED 점등 데이터 가 저장될 8BIT 변수 선언
    int i;
    PORTA = 0XFF;  // PORT A 초기값
    DDRA = 0XFF; // PORT A 출력 값 으로 사용



    while(1){ //  =========== 무한 반복 ===============
        buff = 0X01;  // 초기 점등데이터 저장 : BUFF <-- 0B11111110;

            for(i=1; i<8; i++){

            PORTA = ~buff;  //PORT A 로 buff data 출력 : LED 점등  // 정논리로 이용하여 사용한다.
            delay_ms(500);  // 0.5초 시간 지연

            buff <<= 1; // 다음 점등데이터 준비

        }

    }      // ---------------------------------


}
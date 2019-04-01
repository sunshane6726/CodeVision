#include <90can128.h>
#include <delay.h>

void main(void){

    unsigned char buff;  //LED 점등 데이터 가 저장될 8BIT 변수 선언

    PORTA = 0XFF;  // PORT A 초기값
    DDRA = 0XFF; // PORT A 출력 값 으로 사용

    buff = 0XFF;  // 초기 점등데이터 저장 : BUFF <-- 0B11111110;

    while(1){ //  =========== 무한 반복 ===============
        PORTA = buff;  //PORT A 로 buff data 출력 : LED 점등
        delay_ms(500);  // 0.5초 시간 지연

        if(buff == 0x00)     // buff값이 0x00이면, 모든 LED가
                            // 0n이 되었다면
        {
            buff = 0xfe;  // 점등데이터를 초기값으로 저장
        }

        else{           // 아니면

            buff = buff << 1;    // buff값이 1bit left shift 하여
                                // 다음 점등에이터 준비
        }

    }  // ---------------------------------


}
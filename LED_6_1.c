#include <90can128.h>
#include <delay.h>

void main(void){

    unsigned char buff;  //LED 점등 데이터 가 저장될 8BIT 변수 선언

    PORTA = 0XFF;  // PORT A 초기값
    DDRA = 0XFF; // PORT A 출력 값 으로 사용

    buff = 0XFF;  // 초기 점등데이터 저장 : BUFF <-- 0B11111110;

    while(1){ //  =========== 무한 반복 ===============


            PORTA = buff;
            delay_ms(500);

            if(buff == 0x7f)
            {
                buff = 0xfe;

            }

            else
            {

                buff = buff <<= 1;  //1111 110x (얼마 값인줄 모른디)
                buff = buff | 0x01; //다음 점등데이터 준비
            }
        }

    }      // ---------------------------------



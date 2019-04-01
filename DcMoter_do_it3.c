#include <mega128.h>
#include <delay.h>
#define FWD 0xf9 // 전진 1111 1001
#define LEFT 0xf1 // 좌회전 1111 0001
#define RIGHT 0xf9 // 우회전 1111 1000
#define REV 0xf6 // 후진 1111 0110
#define STOP 0xf0 // 정지 1111 0000


    void MPUinit(void) // ============ 초기화 함수 =============

    {
        DDRB=0xff; PORTB=0xff;   // 왼쪽모터 오른쪽 모터 두개를 사용한다,

        DDRC=0xff; PORTC=0xff;
        TCCR1A = 0x29; // PWM 초기화 ------
        TCCR1B = 0x03; // 00101001 8비트 위상변경 PWM
        TCCR1C = 0X00; // 64분주
        TCNT1 = 0x0000;
    }

void main(void) //============= 메인 함수 ============
{
    MPUinit();
    while (1)
    {
        PORTB =FWD; // 직진  portb 가 0c1a랑 동일하게 사용된다.
        OCR1BL = 50; OCR1CL = 50; // duty ratio = 약 20%
        delay_ms(3000);

        OCR1BL = 120; OCR1CL = 120; // duty ratio = 약 50%
        delay_ms(3000);

        OCR1BL = 180; OCR1CL = 180; // duty ratio = 약 70%
        delay_ms(3000);

        OCR1BL = 255; OCR1CL = 255; // duty ratio = 약 100%
        delay_ms(3000);

         PORTB = STOP;
        delay_ms(1000);
    }
}
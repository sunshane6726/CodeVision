#include <90can128.h>
#include <delay.h>

#define DCM_IN1 PORTB.0 // L298N IN1 Input신호
#define DCM_IN2 PORTB.1 // L298N IN2 Input신호


void DC_M_CW(); // DC Motor CW 구동 함수
void DC_M_CCW(); // DC Motor CCW 구동 함수
void DC_M_STOP(); // DC Motor STOP함수



void main(void)
{
    unsigned char buff0; // 스위치 입력값 저장
    PORTA=0xFF;
    DDRA=0x00; // Port A 스위치 입력
    PORTB=0x00;
    DDRB=0xFF; // Port B 모터 정역제어신호 출력
    PORTC=0xBF; // G세그멘트 ON
    DDRC=0xFF; // Port C FND출력

        while (1)
    {
        buff0 = PINA & 0x03; // 스위치 값 읽음
        delay_ms(5);
        switch(buff0)
        {
            case 0x02: // SW0이 눌리면
            DC_M_CW(); // DC Motor CW 구동
            break;
        
            case 0x01: // SW1이 눌리면
            DC_M_CCW(); // DC Motor CCW 구동
            break;
            
            default: // 스위치가 눌려지지 않으면
            DC_M_STOP(); // DC Motor 정지
            break;
        }
    }
}

void DC_M_CW() // ------ 모터 정회전 함수
{
    DCM_IN1 = 1; // L298N IN1= '1'
    DCM_IN2 = 0; // L298N IN2 = '0'
    PORTC = 0x8e; // FND : "F" 표시
}

void DC_M_CCW() // -------모터 역회전 함수
{
    DCM_IN1 = 0; // L298N IN1 = '0'
    DCM_IN2 = 1; // L298N IN2 = '1’
    PORTC = 0xaf ; // FND : "r" 표시
}

void DC_M_STOP() // ------- 모터 정지 함수
{
    DCM_IN1 = 0; // L298N IN1 = '0'
    DCM_IN2 = 0; // L298N IN2 = '0' ( 둘다 “1” 로 해도 됨)
    PORTC=0xBF; // G세그멘트 O
}
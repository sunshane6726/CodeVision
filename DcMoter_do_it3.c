#include <mega128.h>
#include <delay.h>
#define FWD 0xf9 // ���� 1111 1001
#define LEFT 0xf1 // ��ȸ�� 1111 0001
#define RIGHT 0xf9 // ��ȸ�� 1111 1000
#define REV 0xf6 // ���� 1111 0110
#define STOP 0xf0 // ���� 1111 0000


    void MPUinit(void) // ============ �ʱ�ȭ �Լ� =============

    {
        DDRB=0xff; PORTB=0xff;   // ���ʸ��� ������ ���� �ΰ��� ����Ѵ�,

        DDRC=0xff; PORTC=0xff;
        TCCR1A = 0x29; // PWM �ʱ�ȭ ------
        TCCR1B = 0x03; // 00101001 8��Ʈ ���󺯰� PWM
        TCCR1C = 0X00; // 64����
        TCNT1 = 0x0000;
    }

void main(void) //============= ���� �Լ� ============
{
    MPUinit();
    while (1)
    {
        PORTB =FWD; // ����  portb �� 0c1a�� �����ϰ� ���ȴ�.
        OCR1BL = 50; OCR1CL = 50; // duty ratio = �� 20%
        delay_ms(3000);

        OCR1BL = 120; OCR1CL = 120; // duty ratio = �� 50%
        delay_ms(3000);

        OCR1BL = 180; OCR1CL = 180; // duty ratio = �� 70%
        delay_ms(3000);

        OCR1BL = 255; OCR1CL = 255; // duty ratio = �� 100%
        delay_ms(3000);

         PORTB = STOP;
        delay_ms(1000);
    }
}
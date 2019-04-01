#include <90can128.h>
#include <delay.h>

#define DCM_IN1 PORTB.0 // L298N IN1 Input��ȣ
#define DCM_IN2 PORTB.1 // L298N IN2 Input��ȣ


void DC_M_CW(); // DC Motor CW ���� �Լ�
void DC_M_CCW(); // DC Motor CCW ���� �Լ�
void DC_M_STOP(); // DC Motor STOP�Լ�



void main(void)
{
    unsigned char buff0; // ����ġ �Է°� ����
    PORTA=0xFF;
    DDRA=0x00; // Port A ����ġ �Է�
    PORTB=0x00;
    DDRB=0xFF; // Port B ���� ���������ȣ ���
    PORTC=0xBF; // G���׸�Ʈ ON
    DDRC=0xFF; // Port C FND���

        while (1)
    {
        buff0 = PINA & 0x03; // ����ġ �� ����
        delay_ms(5);
        switch(buff0)
        {
            case 0x02: // SW0�� ������
            DC_M_CW(); // DC Motor CW ����
            break;
        
            case 0x01: // SW1�� ������
            DC_M_CCW(); // DC Motor CCW ����
            break;
            
            default: // ����ġ�� �������� ������
            DC_M_STOP(); // DC Motor ����
            break;
        }
    }
}

void DC_M_CW() // ------ ���� ��ȸ�� �Լ�
{
    DCM_IN1 = 1; // L298N IN1= '1'
    DCM_IN2 = 0; // L298N IN2 = '0'
    PORTC = 0x8e; // FND : "F" ǥ��
}

void DC_M_CCW() // -------���� ��ȸ�� �Լ�
{
    DCM_IN1 = 0; // L298N IN1 = '0'
    DCM_IN2 = 1; // L298N IN2 = '1��
    PORTC = 0xaf ; // FND : "r" ǥ��
}

void DC_M_STOP() // ------- ���� ���� �Լ�
{
    DCM_IN1 = 0; // L298N IN1 = '0'
    DCM_IN2 = 0; // L298N IN2 = '0' ( �Ѵ� ��1�� �� �ص� ��)
    PORTC=0xBF; // G���׸�Ʈ O
}
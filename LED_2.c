#include <90can128.h>
#include <delay.h>

void main(void){

unsigned char buff;             // LED�� ���ؼ� 8��Ʈ�� ����

    PORTA = 0XFF;
    DDRA = 0XFF;

    PORTC = 0XFF;
    DDRC = 0X00;
            while(1){        // ���� �ݺ�

                buff = PINC;             // portc�� �Է³� ����

                PORTA = buff; // LED ���


            }

}
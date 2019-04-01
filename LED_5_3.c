#include <90can128.h>
#include <delay.h>

void main(void){

    unsigned char buff;  //LED ���� ������ �� ����� 8BIT ���� ����

    PORTA = 0XFF;  // PORT A �ʱⰪ
    DDRA = 0XFF; // PORT A ��� �� ���� ���



    while(1){ //  =========== ���� �ݺ� ===============
        buff = 0XFF;  // �ʱ� ������� ���� : BUFF <-- 0B11111110;

        while(buff != 0x00)
        {
            buff <<= 1;  //���� ������ �غ�
            PORTA = buff;  // LED ����
            delay_ms(500);

        }

    }      // ---------------------------------


}
#include <90can128.h>
#include <delay.h>

void main(void){

    unsigned char buff;  //LED ���� ������ �� ����� 8BIT ���� ����

    PORTA = 0XFF;  // PORT A �ʱⰪ
    DDRA = 0XFF; // PORT A ��� �� ���� ���



    while(1){ //  =========== ���� �ݺ� ===============

        buff = 0xfe;      // �ʱ� �������

        while(buff != 0xff)        // �������� 0xff�� �ƴ϶�� �ݺ�
        {
            PORTA = buff;          // ��, buff���� 0xff �ɶ����� �ݺ�
            delay_ms(300);

            buff <<= 1;      // ���� ���� ������ �غ�
            buff != 0x01;


        }

    }      // ---------------------------------


}
#include <90can128.h>
#include <delay.h>

void main(void){

    unsigned char buff;    // �޸� ���� ���� ������ ����ȿ� ó������ �־���Ѵ�.
    unsigned char Led[8] = {0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f};  //LED ���� ������ �� ����� 8BIT ���� ����
    int i;
    PORTA = 0XFF;  // PORT A �ʱⰪ
    DDRA = 0XFF; // PORT A ��� �� ���� ���



    while(1){           //  =========== ���� �ݺ� ===============

     buff = 0x01;  // �ʱ� ������� ���� : BUFF <-- 0B11111110;

            for(i=1; i<8; i++){

            PORTA = Led[i];  //PORT A �� buff data ��� : LED ����  // ������ �̿��Ͽ� ����Ѵ�.
            delay_ms(500);  // 0.5�� �ð� ����



        }

    }      // ---------------------------------


}
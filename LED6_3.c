#include <90can128.h>
#include <delay.h>

void main(void){

    unsigned char buff;  //LED ���� ������ �� ����� 8BIT ���� ����
    int i;
    PORTA = 0XFF;  // PORT A �ʱⰪ
    DDRA = 0XFF; // PORT A ��� �� ���� ���



    while(1){ //  =========== ���� �ݺ� ===============
        buff = 0X01;  // �ʱ� ������� ���� : BUFF <-- 0B11111110;

            for(i=1; i<8; i++){

            PORTA = ~buff;  //PORT A �� buff data ��� : LED ����  // ������ �̿��Ͽ� ����Ѵ�.
            delay_ms(500);  // 0.5�� �ð� ����

            buff <<= 1; // ���� ������� �غ�

        }

    }      // ---------------------------------


}
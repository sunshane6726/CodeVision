#include <90can128.h>
#include <delay.h>

void main(void){

    unsigned char buff;  //LED ���� ������ �� ����� 8BIT ���� ����

    PORTA = 0XFF;  // PORT A �ʱⰪ
    DDRA = 0XFF; // PORT A ��� �� ���� ���

    buff = 0XFF;  // �ʱ� ������� ���� : BUFF <-- 0B11111110;

    while(1){ //  =========== ���� �ݺ� ===============
        PORTA = buff;  //PORT A �� buff data ��� : LED ����
        delay_ms(500);  // 0.5�� �ð� ����

        if(buff == 0x00)     // buff���� 0x00�̸�, ��� LED��
                            // 0n�� �Ǿ��ٸ�
        {
            buff = 0xfe;  // ������͸� �ʱⰪ���� ����
        }

        else{           // �ƴϸ�

            buff = buff << 1;    // buff���� 1bit left shift �Ͽ�
                                // ���� ������� �غ�
        }

    }  // ---------------------------------


}
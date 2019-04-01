#include <90can128.h>
#include <delay.h>

void main(void){

    unsigned char buff;  //LED ���� ������ �� ����� 8BIT ���� ����

    PORTA = 0XFF;  // PORT A �ʱⰪ
    DDRA = 0XFF; // PORT A ��� �� ���� ���

    buff = 0XFF;  // �ʱ� ������� ���� : BUFF <-- 0B11111110;

    while(1){ //  =========== ���� �ݺ� ===============


            PORTA = buff;
            delay_ms(500);

            if(buff == 0x7f)
            {
                buff = 0xfe;

            }

            else
            {

                buff = buff <<= 1;  //1111 110x (�� ������ �𸥵�)
                buff = buff | 0x01; //���� ������� �غ�
            }
        }

    }      // ---------------------------------



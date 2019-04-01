#include <90can128.h>
#include <delay.h>


void main(void){
    PORTA = 0XFF;
    DDRA = 0XFF;

    PORTC = 0XFF;
    DDRC = 0X00;

            while(1){

                if(PINC.0 == 0)  // SW0 ON ?
                {
                    while(PINC.0 == 0);   // SW0 ON �϶� ��� ��� ������ �����ݺ�

                    PORTA = 0X00;       // LED ��� ����


                }
                else if(PINC.1 == 0)   // SW1 ON?
                {
                     while(PINC.1 == 0);     //SW1 OFF �϶�  ��� ���� �ݺ�
                     PORTA = 0XFF;  // LED ��� OFF
                }

            }

}
#include <90can128.h>
#include <delay.h>


void main(void){

    unsigned char keyin; // Ű �Է� ���� ����

    PORTA = 0XFF;       // poat a �ʱⰪ
    DDRA = 0XFF;  // port a �������


    PORTC = 0XFF; //port c �ʱⰪ
    DDRC = 0X00;   // port c �Է�����

            while(1){ //=========== ���� �ݺ� ====================

                keyin = PINC & 0xFF; // & 0000 1111

                switch(keyin){

                    case 0x0e:   // 0000 1100 -> sw0�� on�� ���

                        PORTA= 0B00111111;
                    break;
                    case 0x0d:   // 0000 1101-> sw1�� on�� ���
                        PORTA = 0B11001111;
                    break;
                    case 0x0b:     // 1110 0011-> sw2�� on �� ���
                        PORTA = 0B11110011;
                    break;

                    case 0x07:   // 1111 1100 -> sw3�� on�� ���
                            PORTA = 0B11111100;

                    break;

                }

            }

}
#include <mega128.h>
#include <delay.h>
void main(void)
{
    DDRC = 0xff;
    PORTC = 0x00;
        while(1)
        {
        PORTC = 0x01; delay_ms(50); // ����1 : 0001
        PORTC = 0x02; delay_ms(50); // ����2 : 0010
        PORTC = 0x04; delay_ms(50); // ����3 : 0100
        PORTC = 0x08; delay_ms(50); // ����4 : 1000
        }
}
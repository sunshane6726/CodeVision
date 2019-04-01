#include <mega128.h>
#include <delay.h>
void main(void)
{
    DDRC = 0xff;
    PORTC = 0x00;
        while(1)
        {
        PORTC = 0x01; delay_ms(50); // 蝶變1 : 0001
        PORTC = 0x02; delay_ms(50); // 蝶變2 : 0010
        PORTC = 0x04; delay_ms(50); // 蝶變3 : 0100
        PORTC = 0x08; delay_ms(50); // 蝶變4 : 1000
        }
}
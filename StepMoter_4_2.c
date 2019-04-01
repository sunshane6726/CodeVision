#include <mega128.h>
#include <delay.h>
void main(void)                  // 1상-2상 구동 스테핑 모터
{
    unsigned Step[8] = {0x01, 0x03, 0x02, 0x06, 0x04,
    0x0c, 0x08, 0x09};
    int i;
    DDRC = 0xff;
    PORTC = 0x00;
        while(1)
        {
            for(i=0; i<=7; i++)
            {
            PORTC = Step[i];
            delay_ms(50);
            }
        }
}
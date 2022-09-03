#define DDRB *((volatile char*)0x24)
#define PORTB *((volatile char*)0x25)

#define DDRD *((volatile char*)0x2A)
#define PORTD *((volatile char*)0x2B)

#include <avr/io.h>
#include <util/delay.h>


void main(void)
{

  DDRD |= (1 << 5);
  DDRB |= (1 << 5);

  while (1)
  {
    PORTD ^= (1 << 5);
    PORTB ^= (1 << 5);
    _delay_ms(500);
    PORTD ^= (1 << 5);
    PORTB ^= (1 << 5);
    _delay_ms(500);
  }
}

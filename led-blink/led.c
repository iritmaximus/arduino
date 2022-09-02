#include <avr/io.h>
#include <util/delay.h>

int main(void) {

  // set port b5 as output
  DDRB = DDRB | (1 << DDB5);

  while(1)
  {
    // set portb5 high/on
    PORTB = PORTB | (1 << PORTB5);
    _delay_ms(1000);
    // set portb5 low/off
    PORTB = PORTB & ~(1 << PORTB5);
    _delay_ms(1000);
  }

  return 0;
}

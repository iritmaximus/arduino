#include <avr/io.h>
#include <util/delay.h>

#define shift_light_up(port) port << 1,
#define shift_light_down(port) port >> 1;

// TODO make this general
#define enable_5th_pin_B() DDRB = DDRB | (1 << DDB5);
#define enable_5th_pin_D() DDRD = DDRD | (1 << DDD5);

// port is PORTX where x a-f(?) and pin PORTXY where y 0-7
#define turn_port_on(port, pin) port = port | (1 << pin);
#define turn_port_off(port, pin) port = port & ~(1 << pin)

#define turn_b_port_on() PORTB = PORTB | (1 << PORTB5);
#define turn_b_port_off() PORTB = PORTB & ~(1 << PORTB5);

#define turn_d_port_on() PORTD = PORTD | (1 << PORTD5);
#define turn_d_port_off() PORTD = PORTD & ~(1 << PORTD5);


void main(void)
{
  // set both led lamp registers to output
  // internal on port b5 and external on d5
  enable_5th_pin_B();
  enable_5th_pin_D();

  while(1)
  {
    /* turn_b_port_on(); */
    /* _delay_ms(500); */
    /* turn_b_port_off(); */
    /* /1* turn_d_port_on(); *1/ */
    /* _delay_ms(500); */
    /* /1* turn_d_port_off(); *1/ */
    // set portb5 high/on

    PORTB = PORTB | (1 << PORTB5);
    _delay_ms(500);
    // set portb5 low/off
    PORTB = PORTB & ~(1 << PORTB5);
    PORTD = PORTD | (1 << PORTD5);
    _delay_ms(500);
    PORTD = PORTD & ~(1 << PORTD5);
  }
}

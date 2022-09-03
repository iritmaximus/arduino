// makes avr/io.h include the right microcontroller things
// and makes vim ale work better
#define __AVR_ATmega328P__



#include <avr/io.h>
#include <util/delay.h>



/* void toggle_port( char, int ); */
/* void change_port_on_off( char, int ); */

void main(void)
{
  // set both led lamp registers to output
  // internal on port b5 and external on d5
  /* toggle_port('b', 1); */
  /* toggle_port('d', 1); */
  /* DDRB |= (1 << DDB5); */
  DDRD |= (1 << DDD5);

  while(1)
  {

    // turn internal lamp on
    /* change_port_on_off('b', 1); */
    /* PORTB ^= (1 << PORTB5); */
    // wait
    PORTD ^= (1 << PIND5);
    _delay_ms(500);
    // turn internal lamp off
    /* change_port_on_off('b', 0); */
    /* PORTB ^= (1 << PORTB5); */
    // turn external lamp on
    _delay_ms(10);
    /* change_port_on_off('d', 1); */
    // wait
    PORTD ^= (1 << PIND5);
    _delay_ms(500);
    // turn external lamp off
    /* change_port_on_off('d', 0); */
    _delay_ms(10);
    // repeat
  }
}

// toggles port5 of the b and d ports to output
/* void toggle_port( char b_or_d, int on_or_off ) */
/* { */
/*   if (b_or_d == 'b') { */
/*     switch ( on_or_off ) { */
/*       case 1: */
/*         // on/output */
/*         DDRB |= (1 << DDB5); */
/*       case 0: */
/*         // off */
/*         DDRB &= ~(1 << DDB5); */
/*     } */
/*   } else if (b_or_d == 'd') { */
/*     switch ( on_or_off ) { */
/*       case 1: */
/*         // on/output */
/*         DDRD |= (1 << DDD5); */
/*       case 0: */
/*         // off */
/*         DDRD &= ~(1 << DDD5); */
/*     } */
/*   } */
/* } */

/* void change_port_on_off( char b_or_d, int high_or_low ) */
/* { */
/*   if (b_or_d == 'b') { */
/*     switch ( high_or_low ) { */
/*       case 1: */
/*         // high/on */
/*         PORTB |= (1 << PORTB5); */
/*       case 0: */
/*         // low/off */
/*         PORTB &= ~(1 << PORTB5); */
/*     } */
/*   } else if (b_or_d == 'd') { */
/*     switch ( high_or_low ) { */
/*       case 1: */
/*         // high/on */
/*         PORTD |= (1 << PORTD5); */
/*       case 0: */
/*         // low/off */
/*         PORTD &= ~(1 << PORTD5); */
/*     } */
/*   } */
/* } */

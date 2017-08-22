/*
 * Uno_FreQ_Con.cpp
 *
 * Created: 22/08/2017 PM 08:33:30
 * Author : Shaikh Ahmed
 */ 
#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>


#define DDR_HIGH(DR,pin)	DR |=(1 << pin)
#define DDR_LOW(DR,pin)		DR &=~(1 << pin)


#define HIGH(Port,pin)		Port |=(1 << pin)
#define LOW(Port,pin)		Port &=~(1 << pin)
#define delay(ms)			_delay_ms(ms)

void Frequncy(uint8_t freq)
{
	TCCR1B |=(1<<CS12) | (1<<WGM12);
	TIMSK1|=(1 <<OCIE1A);
	
	OCR1A =(F_CPU/(freq*2*256)-1);
}
int main(void)
{	
	DDR_HIGH(DDRB,5);
	Frequncy(10);
	sei();
  
    while (1) 
    {
    }
}

ISR(TIMER1_COMPA_vect)
{
	PORTB ^=(1<<PINB5);
}
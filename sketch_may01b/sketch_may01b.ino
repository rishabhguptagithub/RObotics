#include<avr/io.h>

#define FOSC 16000000 // Clock Speed
#define BAUD 9600
#define BAUDRATE FOSC/16/BAUD-1



void usart_init(void)
{
    UBRR0H=(unsigned char)(BAUDRATE>>8);
    UBRR0L=(unsigned char)(BAUDRATE);
    UCSR0B |= (1<<RXEN0) | (1<<TXEN0);
    UCSR0C |= (3<<UCSZ00);
  
}




unsigned char uart_receive(void)
{
  while(!(UCSR0A) & (1<<RXC0))
  return UDR0 ;
}


int main()
{
  unsigned char a;
  usart_init();
  char buffer[10];
  while(1)
    {
        a=uart_receive();                   // save the received data in a variable
        itoa(a,buffer,10);                  // convert numerals into string
        Serial.print(buffer);
        _delay_ms(100);                     // wait before next attempt
    }
  
  
  
  
}


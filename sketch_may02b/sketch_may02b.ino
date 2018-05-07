#define FOSC 16000000UL // Clock Speed
#define BAUD 9600
#define BAUDRATE ((FOSC)/(16UL*BAUD)-1)
#include<avr/io.h>

void usart_init(void)
{
    UBRR0H=(BAUDRATE>>8);
    UBRR0L= BAUDRATE;
    UCSR0B |= (1<<RXEN0) | (1<<TXEN0);
    UCSR0C |= (3<<UCSZ00);
}
unsigned char uart_receive(void)
{
  while(!(UCSR0A) & (1<<RXC0))
  return UDR0;
}
int main()
{
  pinMode(0,0);
  pinMode(13,1);
  unsigned char a;
  usart_init();
  while(1){
  a=uart_receive();
  if (a=='75'){
  digitalWrite(13,1);
  delay(500);
  digitalWrite(13,0);
  delay(500);
  }
  if (a==97){
  digitalWrite(13,1);
  delay(1500);
  digitalWrite(13,0);
  delay(1500);
  }
  digitalWrite(13,0);
}}


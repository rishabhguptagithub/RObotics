#include <avr/io.h>


#define F_CPU 16000000UL    
#define BAUD 9600                           // define baud
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)    // set baudrate value for UBRR
  

                 // set the CPU clock
void USART_Init()
{
    /*Set baud rate */
    UBRR0H = (unsigned char)(BAUDRATE>>8);
    UBRR0L = (unsigned char)BAUDRATE;
    //Enable receiver and transmitter */
    UCSR0B = (1<<RXEN0)|(1<<TXEN0);
    /* Set frame format: 8data, 2stop bit */
    UCSR0C = (3<<UCSZ00);
    }
unsigned char USART_Receive( void )
    {
        /* Wait for data to be received */
        while ( !(UCSR0A & (1<<RXC0)) )
        ;
        _delay_ms(100);
        /* Get and return received data from buffer */
        return UDR0;
    }
int main(void)
{
    /* Replace with your application code */
 Serial.begin(9600);
 USART_Init();
 unsigned char a;
 char buffer[10];
    while (1) 
    {
        a=USART_Receive();
        itoa(a,buffer,10);
        _delay_ms(50);
        Serial.println(buffer);
        _delay_ms(50);
    }
}

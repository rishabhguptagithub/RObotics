
#define FOSC 16000000UL // Clock Speed
#define BAUD 9600
#define BAUDRATE ((FOSC)/(16*BAUD)-1)
#include<avr/io.h>
//#include<Servo.h>
//Servo myservo;
int pos = 0;
void usart_init(void)
{
    UBRR0H=(unsigned char)(BAUDRATE>>8);
    UBRR0L=(unsigned char)(BAUDRATE);
    UCSR0B |= (1<<RXEN0) | (1<<TXEN0);
    UCSR0C |= (3<<UCSZ00);
}

void servo_setup(){
   myservo.attach(6);
}

unsigned char uart_receive(void)
{
  while(!(UCSR0A) & (1<<RXC0))
  return UDR0;
}
int main()
{
  unsigned char a;
  usart_init();
//  servo_setup();
  while(1){
     a=uart_receive();
//     for (pos = 0; pos <= a; pos += 1) { // goes from 0 degrees to 180 degrees
//     myservo.write(pos);              // tell servo to go to position in variable 'pos'
//     delayMicroseconds(15/1000);                       // waits 15ms for the servo to reach the position
//  }
//  for (pos = a; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
//     myservo.write(pos);              // tell servo to go to position in variable 'pos'
//     delayMicroseconds(15/1000);                       // waits 15ms for the servo to reach the position
//    }  
//  }
if (a==97){
  digitalWrite(13,1);
  delay(500);
  digitalWrite(13,0);
  delay(500);
  
  }
if (a=='50'){
  digitalWrite(13,1);
  delay(1500);
  digitalWrite(13,0);
  delay(1500);
  
}
}


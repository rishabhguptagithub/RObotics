#include<avr/io.h>

volatile int timer_over;

int timer(){
  TCCR1B |= (1<<CS01);
  TCNT1=0;
  sei();
  TIMSK1 |=(1<<TOIE0);
  timer_over=0;
  
}

ISR(TIMER1_OVF_vect){
  timer_over++;
  
}

int main(){
  DDRD=B00000100;
  timer();
  while(1){
    if (timer_over >=31){
      
        PORTD=B0000100;
        TCNT1=0;
        timer_over=0;
      
    }
    else{
      PORTD=B0000000;
      
    }
   
    
  }
}


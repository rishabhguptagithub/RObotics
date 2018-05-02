#import <avr/io.h>
#import <avr/interrupt.h>

volatile uint8_t tot_overflow;


int timers(){
  TCCR1B |=(1<<CS10);
  TCNT1=0;
  TIMSK1 |= (1<<TOIE0);
  sei();
  tot_overflow=0;
}

ISR(TIMER1_OVF_vect){
  tot_overflow++;
  if (tot_overflow >100){
        
        PORTD=B0000100;
        tot_overflow=0;
        TCNT1=0;
      }
  else{
        PORTD=B0000000;
      }
  
  
  
}
int main(){
  DDRD |= B00000100;
  timers();
  
    
  while(1){
    
  }
}


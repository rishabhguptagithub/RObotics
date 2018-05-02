#import <avr/io.h>
#import <avr/interrupt.h>

int timers(){
  TCCR1B |=(1<<CS10);
  TCNT1=0;
}
int main(){
  DDRD |= B00000100;
  timers();
  int c=0;
  while(1){
    c++;
    if(TCNT1>65500){
      if (c%15 == 0){
        PORTD=B0000100;
      }
      else{
        PORTD=B0000000;
      }
      TCNT1=0;
    }
  }
}


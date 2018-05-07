#include<avr/io.h>
void timer(){
  
  TCCR1B|=(1<<CS10);
  TCNT1=0;
  
}

int main(){
  timer();
  DDRD = B00000100;
  while(1)
  {
    if(TCNT1 > 60000){
      PORTD =B00000000;
    }
    
  
    else{
      PORTD==B00000100;
    }
  }
}


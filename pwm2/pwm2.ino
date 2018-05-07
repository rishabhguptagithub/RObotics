#include<avr/io.h>

void pwm_inter(){
  TCCR0A= (1<<COM0A1) | (1<<WGM01) | (1<<WGM00) ;
  TCCR0B=(1<<CS00);
  TCNT0=0;
  DDRD |= (1 << DDD6);
}

int main(){
  
  pwm_inter();
  while(1){
    for (uint8_t i=0;i<255;i++){
      OCR0A=i;
      _delay_ms(50);
    }
    for(uint8_t i=255;i>=0;i++){
      OCR0A=i;
      _delay_ms(50);
    }
  }
}


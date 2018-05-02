void adc_init()
{
  ADMUX=1<<REFS0;
  ADCSRA=(1<<ADEN | 1<<ADPS2 | 1<<ADPS1 | 1<<ADPS0)
}

uint16_t adc_read(uint8_t ch)
{
  ch =ch& 0b00000111;
  ADMUX=(ADMUX & 0xF8) | ch;

  ADCSRA |=1<<ADSC;
  while(ADCSRA & (1<<ADSC));
  return(ADC);
  
}

int main()
{
  uint16_t adc_result0,adc_result1;
  char int_buffer[10];
  DDRC=0x01;

  


  adc_init();
  delay(50);
  while(1){
    conv_d0=adc_read(0);
    conv_d1=adc_read(1);
    if(conv_d0 <lthres && conv_d1<rthres){
      PORTA|=0x01;
    }
    
    else{
      PORTC=0x00;
      
      
    }
    
  }
}


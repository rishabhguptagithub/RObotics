#include<avr/io.h>

void adc_init()
{
  ADMUX |= 1<<REFS0;
  ADCSRA |=(1<<ADEN)| (1<<ADPS0)| (1<<ADPS1)| (1<<ADPS2);
}

uint16_t adc_read(uint8_t ch)
{
  ch &=0b00000111;
  ADMUX=(ADMUX & 0xF8) | ch;
  ADCSRA |=1<<ADSC;
  while(ADCSRA & (1<<ADSC));
  return(ADC);
}

int main()
{
  Serial.begin(9600);
  uint16_t adc_result;
  adc_init();
  _delay_ms(100);
  pinMode(2, OUTPUT);
  
  while(1)
  {
    adc_result=adc_read(0);
    Serial.println(adc_result);
    if (adc_result<=400)
    {
      digitalWrite(2, HIGH);
      Serial.println("LED is on");
    }
    else
    {
      digitalWrite(2, LOW);
      Serial.println("LED is off");
    }
    _delay_ms(20);
  }
  
  
}


#include<avr\io.h>
#include<Wire.h>

#define adxlr_add (0x53)
byte values[6];
char output[512];

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  
  Wire.beginTransmission(adxlr_add);
  Wire.write(0x2D);
  Wire.write(0);
  Wire.endTransmission();

  Wire.beginTransmission(adxlr_add);
  Wire.write(0x2D);
  Wire.write(16);
  Wire.endTransmission();

  Wire.beginTransmission(adxlr_add);
  Wire.write(0x2D);
  Wire.write(8);
  Wire.endTransmission();
  DDRD=0b00000100;
 // pinMode(2,OUTPUT);

  
  
}

void loop()
{
  int xyz=0x32;
  int x,y,z;

  Wire.beginTransmission(adxlr_add);
  Wire.write(xyz);
  Wire.endTransmission();

  Wire.beginTransmission(adxlr_add);
  Wire.requestFrom(adxlr_add,6);

  int i=0;
  while(Wire.available())
  {
    values[i]=Wire.read();
    i++;
    
  }
  Wire.endTransmission();

  x = (((int)values[1]) << 8) | values[0]; 
  y = (((int)values[3])<< 8) | values[2]; 
  z = (((int)values[5]) << 8) | values[4]; 
  x+=116;
  y+=19;
  z=0;
  y=y/29.5;
  x-=5;
  x=x/31;
  
  sprintf(output, "%d %d %d", x, y, z); 
  Serial.print(output);
  
   
  
  if(x>=7 | y>=7 | x<=-7 | y<=-7)
  {
    PORTD=0b00000100;
   // digitalWrite(2,HIGH);
  }
  else
  {
    PORTD=0b00000000;
    digitalWrite(2,LOW);
  }
  Serial.write(10); 
  delay(1000);

  
  
}


#include <Wire.h>
//--- Accelerometer Register Addresses
#define Power_Register 0x2D
#define X_Axis_Register_DATAX0 0x32 // Hexadecima address for the DATAX0 internal register.
#define X_Axis_Register_DATAX1 0x33 // Hexadecima address for the DATAX1 internal register.
#define Y_Axis_Register_DATAY0 0x34 
#define Y_Axis_Register_DATAY1 0x35
#define Z_Axis_Register_DATAZ0 0x36
#define Z_Axis_Register_DATAZ1 0x37
int ADXAddress = 0x53;  //Device address in which is also included the 8th bit for selecting the mode, read in this case.
int X0,X1,X_out;
int Y0,Y1,Y_out;
int Z1,Z0,Z_out;
float Xa,Ya,Za;
void setup() {
  Wire.begin(); // Initiate the Wire library    
  Serial.begin(9600);    
  delay(100);
  
  Wire.beginTransmission(ADXAddress);
  Wire.write(Power_Register); // Power_CTL Register
  // Enable measurement
  Wire.write(8); // Bit D3 High for measuring enable (0000 1000)
  Wire.endTransmission();
}
void loop() {
  // X-axis
  Wire.beginTransmission(ADXAddress); // Begin transmission to the Sensor 
  //Ask the particular registers for data
  Wire.write(X_Axis_Register_DATAX0);
  Wire.write(X_Axis_Register_DATAX1);  
  Wire.endTransmission(); // Ends the transmission and transmits the data from the two registers
  Wire.requestFrom(ADXAddress,2); // Request the transmitted two bytes from the two registers
  if(Wire.available()<=2) {  // 
    X0 = Wire.read(); // Reads the data from the register
    X1 = Wire.read();
    /* Converting the raw data of the X-Axis into X-Axis Acceleration
     - The output data is Two's complement 
     - X0 as the least significant byte
     - X1 as the most significant byte */ 
    X1=X1<<8;
    X_out =X0+X1;
    Xa=X_out/256.0; // Xa = output value from -1 to +1, Gravity acceleration acting on the X-Axis
  }
  // Y-Axis
  Wire.beginTransmission(ADXAddress); 
  Wire.write(Y_Axis_Register_DATAY0);
  Wire.write(Y_Axis_Register_DATAY1);  
  Wire.endTransmission(); 
  Wire.requestFrom(ADXAddress,2);
  if(Wire.available()<=2) { 
    Y0 = Wire.read();
    Y1 = Wire.read();
    Y1=Y1<<8;
    Y_out =Y0+Y1;
    Ya=Y_out/256.0;
  }
  // Z-Axis
  Wire.beginTransmission(ADXAddress); 
  Wire.write(Z_Axis_Register_DATAZ0);
  Wire.write(Z_Axis_Register_DATAZ1);  
  Wire.endTransmission(); 
  Wire.requestFrom(ADXAddress,2);
  if(Wire.available()<=2) { 
    Z0 = Wire.read();
    Z1 = Wire.read();
    Z1=Z1<<8;
    Z_out =Z0+Z1;
    Za=Z_out/256.0;
  }
  // Prints the data on the Serial Monitor
  Serial.print("Xa= ");
  Serial.print(Xa);
  Serial.print("   Ya= ");
  Serial.print(Ya);
  Serial.print("   Za= ");
  Serial.println(Za);
}

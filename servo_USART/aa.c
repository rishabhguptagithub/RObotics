volatile int a=0,b=0;
void setup()
{
	Serial.begin(9600);
	pinMode(6,OUTPUT);
	Serial.setTimeout(1);
}
void loop(){
	if (Serial.available()>0){
		a=Serial.read();
		b=a.toInt();			//except this line baaki sab shi  h ye test krne k liye meko arduino chahiye ya m mer apurana code dekhta
		//1deg=0.1/60 secs
		digitalWrite(6,1);
		delay(b*0.1/60000);
		digitalWrite(6,0);
	}
}
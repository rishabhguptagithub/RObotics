void setup() {
  pinMode(8,OUTPUT);// put your setup code here, to run once:
  pinMode(7,OUTPUT);
}

void loop() {
  digitalWrite(8,HIGH);
  delay(50);
  
  digitalWrite(8,LOW);
  delay(50);
  digitalWrite(6,HIGH);
  delay(50);
  digitalWrite(6,LOW);
  delay(50);
  digitalWrite(7,HIGH);
  delay(50);
  digitalWrite(7,LOW);
  delay(50);
  digitalWrite(5,HIGH);
  delay(50);

  delay(50);
  
  // put your main code here, to run repeatedly:

}

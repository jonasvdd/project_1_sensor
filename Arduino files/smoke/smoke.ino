#define smk A2

void setup() {
  // put your setup code here, to run once:
  pinMode(smk,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int analogSensor = analogRead(smk);
  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  
  delay(100);
}

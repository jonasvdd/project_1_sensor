#define water 12

void setup() {
  // put your setup code here, to run once:
  pinMode(water,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensor = digitalRead(water);
  Serial.println(sensor);
}

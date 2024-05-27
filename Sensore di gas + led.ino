
int pin8 = 8;
int sensor = A0;
int sensorValue = 0;

void setup() {
  pinMode(pin8, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(sensor);
  Serial.println(sensorValue, DEC);
  if (sensorValue > 500) {
    digitalWrite(pin8, HIGH);
  }
  else {
    digitalWrite(pin8, LOW);
  }

}

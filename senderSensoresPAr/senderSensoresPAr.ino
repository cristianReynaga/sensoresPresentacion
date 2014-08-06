// 
// Sensor de luz prototipo

#define ARRAY_SIZE 4

int myLed=13;
int timerOn=800;
int timerOff=50;


int sensorPin[]={
 A0, A1, A2, A3};
int valSensor[ARRAY_SIZE];
int value[ARRAY_SIZE];

void setup() {

  Serial.begin(115200);

  for (int i=0; i<ARRAY_SIZE; i++) {
    pinMode(sensorPin[i], INPUT);
  }

}


void loop() {

  for (int i=0; i<ARRAY_SIZE; i++) {
    value[i]=analogRead(sensorPin[i]);

  }

  Serial.print(value[0], DEC);
  Serial.print(",");
  Serial.print(value[1], DEC);
  Serial.print(",");
  Serial.print(value[2], DEC);
  Serial.print(",");
  Serial.print(value[3], DEC);
  Serial.print(",");
  Serial.println();
  delay(50);

}


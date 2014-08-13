//
// Sensor de luz, sonido, temperatura y humedad prototipo

#include "DHT.h" //cargamos la librería DHT

#define ARRAY_SIZE 4

// Variables
byte Offset = 0;
#define DHTPIN 2 //Seleccionamos el pin en el que se //conectará el sensor
#define DHTTYPE DHT11 //Se selecciona el DHT11 (hay //otros DHT)
DHT dht(DHTPIN, DHTTYPE); //Se inicia una variable que será usada por Arduino para comunicarse con el sensor
unsigned long time;
// Variables Luz
int lightPin = 5;  //Pin de la foto-resistencia
int light = 0;   //Variable light
int light0 = 0;
float Res0 = 10.0;
//int min = 0;       //valor mínimo que da la foto-resistencia
//int max = 1000;       //valor máximo que da la foto-resistencia
// Variables ruido
int electret = 0;
int lect = 0;
int noise = 0;
int threshold = 760;


//int sensorPin[] = {
//  A0, A1, A2, A3
//};
int valSensor[ARRAY_SIZE];
int value[ARRAY_SIZE];

void setup() {

  Serial.begin(115200);
  dht.begin();

//  for (int i = 0; i < ARRAY_SIZE; i++) {
//    pinMode(sensorPin[i], INPUT);
//  }

}


void loop() {
  //Temperatura
  int temp = dht.readTemperature() - 6;
  //Humedad
  int hum = dht.readHumidity() + 7;
  //Ruido
  int lect = analogRead(electret);
  noise = lect - threshold;
  //Luz
  light0 = analogRead(lightPin);   // Read the analogue pin
  float Vout0 = light0 * 0.0048828125;  // calculate the voltage
  light = 500 / (Res0 * ((5 - Vout0) / Vout0));


//  for (int i = 0; i < ARRAY_SIZE; i++) {
//    value[i] = analogRead(sensorPin[i]);
//
//  }


  Serial.print(temp, DEC);
  Serial.print(",");
  Serial.print(hum, DEC);
  Serial.print(",");
  Serial.print(noise, DEC);
  Serial.print(",");
  Serial.print(light, DEC);
  Serial.print(",");
  Serial.println();
  delay(50);

}


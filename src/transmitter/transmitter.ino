#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

// initialize MPU6050 and nRF24L01 
Adafruit_MPU6050 mpu;
RF24 radio(6, 5);  // CE, CSN

const byte address[6] = "03401";
bool working;

void setup() {
  Serial.begin(115200);
  // 9600 baud seems to be the sweetspot
  
  // radio init
  radio.begin();
  radio.openWritingPipe(address);
  radio.stopListening();
  
  working = radio.isChipConnected();
  if (working == true) 
    Serial.println("chip is connected");

  // gyro init
  if (!mpu.begin()) {
    Serial.println("Error: no MPU6050 chip.");
    while (1) {
      delay(10);
    }
  }

  mpu.setGyroRange(MPU6050_RANGE_250_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  // just gives us time to set the ranges and filter bandwidth
  delay(100);
}

void loop() {
  bool sent;
  int failcount = 0;
  bool fell = false;
  const char *text = "Fall detected.";
  sensors_event_t a, g, temp;

  while (failcount < 10) {     
    // check if fell 
    
    mpu.getEvent(&g, &a, &temp);

    // in units of radians/s
    if (abs(g.gyro.x) > 24.0 || abs(g.gyro.y) > 7.0) {
      fell = true;
    } 
    
    if (fell == true) {
        sent = radio.write(&text, sizeof(text));
        fell = false;
    
    if (sent) 
      Serial.println("Success");
    else {
      Serial.println("Error: failure to send");
      failcount++;
    }
    
    delay(1000);
    
    }  
  }
  
  Serial.println("Debug needed.");
  delay(1000);
  exit(0);
}

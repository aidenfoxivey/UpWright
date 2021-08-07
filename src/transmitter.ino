#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(6, 5);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "03401";
bool working;

void setup() {
  Serial.begin(9600);
  // 9600 baud seems to be the sweetspot
  
  radio.begin();
  radio.openWritingPipe(address);
  radio.stopListening();
  
  working = radio.isChipConnected();
  if (working == true) 
    Serial.println("chip is connected");
}

void loop() {
  bool sent;
  int failcount = 0;
  bool fell = true;
  const char *text = "Fall detected.";

  while (failcount < 5) {     
    if (fell == true) {
        sent = radio.write(&text, sizeof(text));
    
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

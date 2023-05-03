/*
  RainCatcher
  print tipping bucket count

  Board : KITS ESP32 EDU
  Upload Speed: "921600"
  Partition Scheme : "No OTA (Laege APP)"
  Core Debug Level : "None"
  
  Created : 2023.05.03
  By ballofish
  https://github.com/ballofish/RainCatcher
*/

const uint32_t BAUDRATE = 115200;
const uint8_t PIN_PULSE = 5;
uint16_t count = 0;
boolean tippingState = false;

void setup() {
  Serial.begin(BAUDRATE);
  pinMode(PIN_PULSE, INPUT);
  digitalWrite(PIN_PULSE, HIGH);
  delay(500);
}

void loop() {
  if ( (tippingState == true) && !digitalRead(PIN_PULSE) ) {
    tippingState = false;
    Serial.println(count);
    delay(200);
  }
  else if ( (tippingState == false) && digitalRead(PIN_PULSE) ){
    tippingState = true;
    count++;
    delay(200);
  }
}

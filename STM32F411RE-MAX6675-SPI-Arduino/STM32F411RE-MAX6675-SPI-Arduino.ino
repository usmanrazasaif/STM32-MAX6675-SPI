#include "SPI.h"

#define CS_pin 10

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  SPI.setDataMode(SPI_MODE1);
  SPI.setBitOrder(MSBFIRST);
  SPI.setClockDivider(SPI_CLOCK_DIV32);
  SPI.begin();

  pinMode(CS_pin, OUTPUT);
  digitalWrite(CS_pin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  uint16_t data;
  float temperature; 
  
  digitalWrite(CS_pin, LOW);

  data = SPI.transfer16(0);

  digitalWrite(CS_pin, HIGH);

  if ( data & 0x0004){
    Serial.println("Not A Number");
  }
  else {
    temperature =  (data >> 3) / 4;
  }

  Serial.println(temperature);
  delay(500);
}

// Library: TMRh20/RF24, https://github.com/tmrh20/RF24/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 nRF(7, 8);      // CE, CSN
const byte address[6] = "00001";
void setup() {
  Serial.begin(9600);
  nRF.begin();
  nRF.openReadingPipe(0, address);
  nRF.setPALevel(RF24_PA_MIN);
  nRF.startListening();
}
void loop() {
  if (nRF.available()) {
    char text[32] = "";
    nRF.read(&text, sizeof(text));
    Serial.println(text);
  }
}

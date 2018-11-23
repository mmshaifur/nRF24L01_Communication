// Library: TMRh20/RF24, https://github.com/tmrh20/RF24/


#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 nRF(7, 8); // CE, CSN

const byte address[6] = "00001";
void setup() {
  nRF.begin();
  nRF.openWritingPipe(address);
  nRF.setPALevel(RF24_PA_MIN);
  nRF.stopListening();
}
void loop() {
  const char text[] = "Hello World";
  nRF.write(&text, sizeof(text));
  delay(1000);
}

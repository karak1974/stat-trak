#include <Arduino.h>
#include <EEPROM.h>

int counterAddress = 0;
int counterValue = 0;

// input is required to handle dividing too
void add_counter(int i) {
  int counter = EEPROM.read(counterAddress);
  counter += i;
  counterValue = counter;
  EEPROM.write(counterAddress, counter);
  EEPROM.commit();
}

int get_counter() {
  int counter = EEPROM.read(counterAddress);
  counterValue = counter;
  return counter;
}

void setup() {
  Serial.begin(115200);
  Serial.println("[i] Stat-Trak v0.1 booting");

  EEPROM.begin(512);
  counterValue = get_counter();
  add_counter(1);
}

void loop() {
  Serial.printf("[D] Value is %d\n", counterValue);
  sleep(1);
}

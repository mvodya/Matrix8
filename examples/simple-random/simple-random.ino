// Matrix8 library example
// Simple random
// by Mark Vodyanitskiy (@mvodya) 2018
#include <matrix8.h>

// Init matrix8
//   latch - 7
//   clock - 6
//   data  - 8
Matrix8 matrix(7, 6, 8);

// External buffer for matrix
byte *buf;
// Timer for update matrix
unsigned long timer = 0;

void setup() {}

void update() {}

void loop() {
  // Timer for update
  if (timer + 1000000 < micros()) {
    timer = micros();
    update();
  }
  // Draw matrix
  matrix.draw();
}
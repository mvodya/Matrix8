// Matrix8 library example
// Smile animation
// by Mark Vodyanitskiy (@mvodya) 2018
#include <matrix8.h>

// External buffer for matrix
byte *buf;

// Init matrix8
//   latch - 7
//   clock - 6
//   data  - 8
Matrix8 matrix(7, 6, 8);

bool switcher = false;
unsigned long timer = 0;

byte key1[] = {B00111100,
               B01000010,
               B10100101,
               B10000001,
               B10111101,
               B10000001,
               B01000010,
               B00111100};
byte key2[] = {B00111100,
               B01000010,
               B10100101,
               B10000001,
               B10100101,
               B10011001,
               B01000010,
               B00111100};

void setup() {
  // Set pointer to matrix buffer
  buf = matrix.getBuffer();
}

void update() {
  // Switch keys
  switcher = !switcher;
  for (int i = 0; i < 8; i++) {
    if (switcher)
      buf[i] = key1[i];
    else
      buf[i] = key2[i];
  }
}


void loop() {
  // Timer for update
  if (timer + 1000000 < micros()) {
    timer = micros();
    update();
  }
  // Draw matrix
  matrix.draw();
}
// Matrix8 library example
// Random fly
// by Mark Vodyanitskiy (@mvodya) 2018
#include <matrix8.h>

// Init matrix8
//   latch - 7
//   clock - 6
//   data  - 8
Matrix8 matrix(7, 6, 8);

// Last update for timer
unsigned long timer = 0;
// Dot position
struct Position {
  unsigned int x : 4;
  unsigned int y : 4;
} position;

void update() {
  // Clear last dot
  matrix.set(position.x, position.y, 0);
  // Create random value (-1 or 1)
  int value;
  if (random(2) == 1)
    value = 1;
  else
    value = -1;
  // Add random offset for position
  if (random(2) == 1)
    position.x += value;
  else
    position.y += value;
  // Position limits
  position.x %= 8;
  position.y %= 8;
  // Set matrix
  matrix.set(position.x, position.y, 1);
}

void setup() {
  // Set start position
  position.x = 4;
  position.y = 4;
  // Random seed (using noise from analog pin)
  randomSeed(analogRead(0));
}

void loop() {
  // Timer for update
  if (timer + 100000 < micros()) {
    timer = micros();
    update();
  }
  // Draw matrix
  matrix.draw();
}
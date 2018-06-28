// Matrix8 library example
// Simple Twirl
// by Mark Vodyanitskiy (@mvodya) 2018
#include "matrix8.h"

// Init matrix8
//   latch - 7
//   clock - 6
//   data  - 8
Matrix8 matrix(7, 6, 8);

// Last tick for timer
unsigned long timer = 0;
// Animation state (direction)
enum State { UP = 0, RIGHT, DOWN, LEFT } state;
// Position for animation
struct Position {
  unsigned int x : 4;
  unsigned int y : 4;
} position;
// Animation inversion
bool power = false;
// Offset for twirl
unsigned offset = 4;

// Update drawing
void tick() {
  // Invert and restart animation
  if (offset >= 4) {
    state = UP;
    position.x = 0;
    position.y = 0;
    offset = 0;
    power = !power;
  }
  // Set matrix segment in current position
  matrix.set(position.x, position.y, power);
  // Change position
  switch (state) {
    case UP:
      position.y++;
      if (position.y == 7 - offset) state = RIGHT;
      break;
    case RIGHT:
      position.x++;
      if (position.x == 7 - offset) state = DOWN;
      break;
    case DOWN:
      position.y--;
      if (position.y == offset) state = LEFT;
      break;
    case LEFT:
      position.x--;
      if (position.x <= offset + 1) {
        state = UP;
        offset++;
      }
      break;
  }
}

void setup() {}

void loop() {
  // Timer for update
  if (timer + 100000 < micros()) {
    timer = micros();
    tick();
  }
  // Draw matrix
  matrix.draw();
}
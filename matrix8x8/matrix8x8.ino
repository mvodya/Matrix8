#include "matrix8.h"

// Create matrix8
//   latch - 7
//   clock - 6
//   data  - 8
Matrix8 mat(7, 6, 8);

void setup() {
}

unsigned int a = 0;
int state = 0;
int x = 0, y = 0;
bool stab = true;
void up() {
  
  mat.set(x, y, stab);
  
  if (state == 0)
    x++;
  if (state == 1)
    y++;
  if (state == 2)
    x--;
  if (state == 3)
    y--;

  
  if (state == 0 && x == 7 - a)
    state = 1;
  if (state == 1 && y == 7 - a)
    state = 2;
  if (state == 2 && x == 0 + a)
    state = 3;
  if (state == 3 && y == 1 + a) {
    state = 0;
    a++;
  }
  if (a == 4) {
    mat.set(x, y, stab);
    a = 0;
    x = 0;
    y = 0;
    state = 0;
    stab = !stab;
  }
}

unsigned long ltime = 0;
void loop() {
  if (ltime + 100000 < micros()) {
    ltime = micros();
    up();
  }
  mat.draw();
}

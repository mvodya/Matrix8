# Matrix8 Library

## LED 8x8 Matrix via shift registers.

![8x8 matrix](https://frogling.com/site/wp-content/uploads/2018/06/DSC_0932.jpg)

This library control LED 8x8 matrix via two shift registers (for example 74HC595).

## How to use

* Download all repo files
* Go to arduino IDE root
* Copy all files to `library/Matrix8`
* Just use!

## Simple example

Drawing cross

```cpp
#include "matrix8.h"

// Init matrix8
//   latch - 7
//   clock - 6
//   data  - 8
Matrix8 matrix(7, 6, 8);

void setup() {
  // Creating two diagonal lines (cross)
  for (int i = 0; i < 8; i++) {
    matrix.set(i, i, true);
    matrix.set(i, 7 - i, true);
  }
}

void loop() {
  // Loop draw
  matrix.draw();
}
```

![8x8 matrix cross](https://frogling.com/site/wp-content/uploads/2018/06/p2212.jpg)

## Functions

* `Matrix8(latch, clock, data)` - init matrix8 constructor
* `set(x, y, value)` - set segment value by position
* `draw()` - draw row by row matrix
* `draw(delay)` - draw with delay after rows print, just for test
* `getBuffer()` - return matrix buffer pointer _(example/smile-animate)_
* `clear()`  - clear matrix buffer
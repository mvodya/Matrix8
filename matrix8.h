#include <Arduino.h>
// Size of matrix (another size doesn't tested)
#define MATRIX_SIZE 8
// Clear registers after initialization
#define MATRIX_REGISTERS_INIT_CLEAR 1

class Matrix8 {
 private:
  int latch_pin_, clock_pin_, data_pin_;
  byte row_;
  byte *buffer_;

 public:
  // Init matrix and create buffer
  Matrix8(int latch_pin, int clock_pin, int data_pin);
  // Init matrix with external buffer
  Matrix8(int latch_pin, int clock_pin, int data_pin, byte &buffer);
  // Draw matrix (row by row method)
  void draw();
  // Draw with delay
  void draw(int del);

  /* DRAWING FUNCTIONS */
  // Set one pixel
  void set(int x, int y, bool value);
  // Clear all buffer
  void clear();

 private:
  // Setup microcontroller pins for output
  void initPins();
};
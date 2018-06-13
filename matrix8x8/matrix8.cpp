#include "matrix8.h"

Matrix8::Matrix8(int latch_pin, int clock_pin, int data_pin) {
  // Set initialization vars
  latch_pin_ = latch_pin;
  clock_pin_ = clock_pin;
  data_pin_ = data_pin;
  row_ = 0;
  // Create buffer
  buffer_ = new byte[MATRIX_SIZE];
}

Matrix8::Matrix8(int latch_pin, int clock_pin, int data_pin, byte &buffer) {
  // Set initialization vars
  latch_pin_ = latch_pin;
  clock_pin_ = clock_pin;
  data_pin_ = data_pin;
  row_ = 0;
  // Set buffer
  buffer_ = buffer;
}

void Matrix8::draw() {
  row_ = 1;
  for (int i = 0; i < MATRIX_SIZE; i++) {
    // Lock latch pin
    digitalWrite(latch_pin_, 0);
    // Write row shift register
    shiftOut(data_pin_, clock_pin_, LSBFIRST, ~row_);
    // Write column shift register
    shiftOut(data_pin_, clock_pin_, LSBFIRST, buffer_[i]);
    // Unlock latch pin
    digitalWrite(latch_pin_, 1);
    // Switch to next row
    row_ <<= 1;
  }
}
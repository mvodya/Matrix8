#include "matrix8.h"

Matrix8::Matrix8(int latch_pin, int clock_pin, int data_pin) {
  // Set initialization vars
  latch_pin_ = latch_pin;
  clock_pin_ = clock_pin;
  data_pin_ = data_pin;
  row_ = 0;
  // Set pins to output
  initPins();
  // Create buffer
  buffer_ = new byte[MATRIX_SIZE];
  // Clear buffer after (shift registers may contain any data)
#if MATRIX_REGISTERS_INIT_CLEAR
  clear();
#endif
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
  // Go to function with zero delay
  draw(0);
}

void Matrix8::draw(int del) {
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
    // Delay
    delay(del);
  }
}

void Matrix8::set(int row, int column, bool value) {
  if (value)
    // LED ON
    buffer_[row] |= (1 << column);
  else
    // LED OFF
    buffer_[row] &= ~(1 << column);
}

void Matrix8::clear() {
  // Set all bytes to zero
  for (int i = 0; i < MATRIX_SIZE; i++) buffer_[i] = 0;
}

void Matrix8::initPins() {
  // Set pins to output
  pinMode(latch_pin_, OUTPUT);
  pinMode(clock_pin_, OUTPUT);
  pinMode(data_pin_, OUTPUT);
}
#include <assert.h>
#include <stdbool.h>

bool accident_detected(double vel, double accel) {
  if (vel >= 15 && accel >= 4) {
    return true;
  }
  return false;
}

int main() {
  assert(accident_detected(15, 4));
  assert(accident_detected(16, 5));
  assert(!accident_detected(13, 4));
  assert(!accident_detected(15, 3));
  return 0;
}
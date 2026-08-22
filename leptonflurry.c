#include <stdint.h>

uint32_t leptonflurry1x32(uint32_t *counter, uint32_t *key) {
  uint32_t a = counter[0] + key[0] + 11111111;
  uint32_t b = counter[1] + key[1];

  a += a << 9;
  a += counter[1] + b;
  a += a << 13;
  b += counter[0] + a;
  a += (b + (b << 7)) ^ (b >> 11);
  b += (a + (a << 15)) ^ (a >> 13);
  a += (b + (b << 9)) ^ (b >> 5);
  b += (a + (a << 13)) ^ (a >> 11);
  a += (b + (b << 7)) ^ (b >> 9);
  return a ^ (a >> 17) ^ b;
}

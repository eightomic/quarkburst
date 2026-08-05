#include <stdint.h>

struct quarkburst1x64_state {
  uint64_t a;
  uint64_t b;
  uint64_t c;
};

struct quarkburst2x64_state {
  uint64_t output[2];
  uint64_t a;
  uint64_t b;
  uint64_t c;
};

struct quarkburst4x64_state {
  uint64_t output[4];
  uint64_t a;
  uint64_t b;
  uint64_t c;
  uint64_t d;
};

uint64_t quarkburst1x64(struct quarkburst1x64_state *s) {
  s->a = ((s->a << 29) | (s->a >> 35)) ^ s->b;
  s->b += 1111111111111111;
  s->c = ((s->c << 41) | (s->c >> 23)) + s->a;
  return s->c;
}

void quarkburst2x64(struct quarkburst2x64_state *s) {
  s->a = ((s->a << 29) | (s->a >> 35)) ^ s->b;
  s->b += 11111111111111111;
  s->output[0] = s->a + s->c;
  s->c = ((s->c << 43) | (s->c >> 21)) + s->a;
  s->output[1] = (s->a + s->b) ^ s->c;
}

void quarkburst4x64(struct quarkburst4x64_state *s) {
  s->a = ((s->a << 29) | (s->a >> 35)) ^ s->b;
  s->b += 111111111111111111;
  s->output[0] = s->a + s->c;
  s->c = ((s->c << 47) | (s->c >> 17)) + s->a;
  s->output[1] = (s->a + s->b) ^ s->c;
  s->output[2] = s->a ^ s->d;
  s->d = ((s->d << 25) | (s->d >> 39)) + s->a;
  s->output[3] = s->a + ((s->d << 21) | (s->d >> 43));
}

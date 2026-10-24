/*
  Copyright © 2026 Eightomic <eightomic@proton.me>

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/

#include <stdint.h>

struct quarkburst64x1_state {
  uint64_t a;
  uint64_t b;
  uint64_t c;
};

struct quarkburst64x2_state {
  uint64_t output[2];
  uint64_t a;
  uint64_t b;
  uint64_t c;
};

struct quarkburst64x4_state {
  uint64_t output[4];
  uint64_t a;
  uint64_t b;
  uint64_t c;
  uint64_t d;
};

struct quarkburst64x8_state {
  uint64_t output[8];
  uint64_t a;
  uint64_t b;
  uint64_t c;
  uint64_t d;
};

void quarkburst64x1(struct quarkburst64x1_state *s) {
  s->a = ((s->a << 29) | (s->a >> 35)) ^ s->b;
  s->b += 1111111111111111;
  s->c = ((s->c << 41) | (s->c >> 23)) + s->a;
}

void quarkburst64x2(struct quarkburst64x2_state *s) {
  s->a = ((s->a << 29) | (s->a >> 35)) ^ s->b;
  s->b += 11111111111111111;
  s->output[0] = s->a + s->c;
  s->c = ((s->c << 43) | (s->c >> 21)) + s->a;
  s->output[1] = (s->a + s->b) ^ s->c;
}

void quarkburst64x4(struct quarkburst64x4_state *s) {
  s->a = ((s->a << 29) | (s->a >> 35)) ^ s->b;
  s->b += 111111111111111111;
  s->output[0] = s->a + s->c;
  s->c = ((s->c << 47) | (s->c >> 17)) + s->a;
  s->output[1] = (s->a + s->b) ^ s->c;
  s->output[2] = s->a ^ s->d;
  s->d = ((s->d << 25) | (s->d >> 39)) + s->a;
  s->output[3] = s->a + ((s->d << 21) | (s->d >> 43));
}

void quarkburst64x8(struct quarkburst64x8_state *s) {
  s->a = ((s->a << 27) | (s->a >> 37)) ^ s->b;
  s->b += 111111111111111111;
  s->output[0] = s->a + s->c;
  s->c = ((s->c << 47) | (s->c >> 17)) + s->a;
  s->output[1] = (s->a + s->b) ^ s->c;
  s->output[2] = s->a ^ s->d;
  s->d = ((s->d << 25) | (s->d >> 39)) + s->a;
  s->output[3] = s->a + ((s->d << 21) | (s->d >> 43));
  s->output[4] = s->b + (s->c ^ (s->c >> 19));
  s->output[5] = s->b + ((s->d << 39) | (s->d >> 25));
  s->output[6] = s->a + ((s->c << 21) | (s->c >> 43));
  s->output[7] = s->a + (s->d ^ (s->d >> 15));
}

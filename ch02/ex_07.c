#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned invert(unsigned x, int p, int n);
unsigned invert_answerskey(unsigned x, int p, int n);

main() {
  printf("%d\n", invert(0, 0, 1));
  printf("%d\n", invert(0, 4, 2));
  printf("%d\n", invert(0, 5, 4));

  printf("%d\n", invert_answerskey(0, 0, 1));
  printf("%d\n", invert_answerskey(0, 4, 2));
  printf("%d\n", invert_answerskey(0, 5, 4));
}

unsigned getbits(unsigned x, int p, int n) {
  return (x >> (p + 1 - n)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
  return x & ~(~(~0 << n) << (p - n + 1)) | ((y & ~(~0 << n)) << (p - n + 1));
}

// this is what I came up with off the top of my head
unsigned invert(unsigned x, int p, int n) {
  // get the n bits from x starting at position p
  // invert them, then set them with setbits
  return setbits(x, p, n, ~getbits(x, p, n));
}

// stolen from the answers key again -
// xor with 1 - invert
// xor with 0 - unchanged
unsigned invert_answerskey(unsigned x, int p, int n) {
  return x ^ ~(~0 << n) << (p + 1 - n);
}

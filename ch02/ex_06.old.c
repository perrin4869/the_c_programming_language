#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned setbits_answerskey(unsigned x, int p, int n, unsigned y);

main() {
  printf("%d\n", setbits(0, 0, 1, ~0));
  printf("%d\n", setbits(0, 4, 2, ~0));
  printf("%d\n", setbits(0, 5, 4, ~0));

  printf("%d\n", setbits_answerskey(0, 0, 1, ~0));
  printf("%d\n", setbits_answerskey(0, 4, 2, ~0));
  printf("%d\n", setbits_answerskey(0, 5, 4, ~0));
}

unsigned getbits(unsigned x, int p, int n) {
  return (x >> (p + 1 - n)) & ~(~0 << n);
}

/* my own solution, result of lack of creativity */
unsigned setbits(unsigned x, int p, int n, unsigned y) {
  int i, b;
  for (i = 0; i < n; i++) {
    b = getbits(y, i, 1);
    if (b)
      x |= 1 << (p - n + i + 1);
    else
      x &= ~(1 << (p - n + i + 1));
  }

  return x;
}

/* stolen from the answers key of the book */
/* clear the bits to be set from x and clear irrelevant bits from y */
unsigned setbits_answerskey(unsigned x, int p, int n, unsigned y) {
  return x & ~(~(~0 << n) << (p - n + 1)) | ((y & ~(~0 << n)) << (p - n + 1));
}

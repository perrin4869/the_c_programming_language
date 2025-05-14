#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, int y);

/*
 * the idea here is:
 * x^0 = x for x=0,1
 * x^1 = ~x for x=0,1
 * x|0 = x for x=0,1
 * x|1 = 1 for x=0,1
 */

main() {
  printf("setbits(0, 0, 1, 1) = %d\n", setbits(0, 0, 1, 1));
  printf("setbits(1, 2, 2, ~0) = %d\n", setbits(1, 2, 2, ~0));
  printf("setbits(1, 3, 2, ~0) = %d\n", setbits(1, 3, 2, ~0));
}

unsigned setbits(unsigned x, int p, int n, int y) {
  y = (y & ~(~0 << n)) << (p - n + 1); /* 00000yyyy00000 */
  x &= ~(~(~0 << n) << (p - n + 1));   /* x & 111100001111 -> xxxx0000xxxx */
  /* return ~x ^ ~y; /1* ~xxxx1111~xxxx ^ 1111~yyyy1111 = xxxxyyyyxxxx *1/ */
  return x | y; /* xxxx0000xxxx ^ 0000yyyy0000 = xxxxyyyyxxxx */
}

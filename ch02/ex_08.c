#include <stdio.h>

int rightrot(unsigned x, int n);

main() {
  int wordlength();

  printf("wordlength: %d\n", wordlength());
  printf("rightrot(1, 1) = %d\n", rightrot(1, 1));
  printf("rightrot(1, 1) = %u\n", rightrot(1, 1));
}

int rightrot(unsigned x, int n) {
  int wordlength();

  int len = wordlength();
  int i;
  int y;

  for (i = 0; i < n; i++) {
    y = x & 1;
    x >>= 1;
    x |= y << (len - 1);
  }

  return x;
}

int wordlength() {
  unsigned int n = ~0;
  int c;
  for (c = 1; n >>= 1; c++)
    ;
  return c;
}

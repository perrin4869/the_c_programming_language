#include <stdio.h>

int bitcount(unsigned x);

main() {
  printf("%d\n", bitcount(16));
  printf("%d\n", bitcount(17));
  printf("%d\n", bitcount(83));
  printf("%d\n", bitcount(91));
  printf("%d\n", bitcount(-91));
}

int bitcount(unsigned x) {
  int b = 0;

  while (x) {
    b++;
    x &= x - 1;
  }

  return b;
}

#include <stdio.h>

int bitcount(int x);
int bitcount_unsigned(unsigned x);

main() {
  printf("%d\n", bitcount(16));
  printf("%d\n", bitcount(17));
  printf("%d\n", bitcount(83));
  printf("%d\n", bitcount(91));
  printf("%d\n", bitcount(-91));

  printf("%d\n", bitcount_unsigned(16));
  printf("%d\n", bitcount_unsigned(17));
  printf("%d\n", bitcount_unsigned(83));
  printf("%d\n", bitcount_unsigned(91));
  printf("%d\n", bitcount_unsigned(-91));
}

// when x is signed, when x is negative, x < 0
// so the loop condition will fail, and it won't count
// the bits
int bitcount(int x) {
  int i;
  for (i = 0; x > 0; i++, x &= (x - 1))
    ;
  return i;
}

int bitcount_unsigned(unsigned x) {
  int i;
  for (i = 0; x > 0; i++, x &= (x - 1))
    ;
  return i;
}

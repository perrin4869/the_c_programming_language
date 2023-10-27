#include <stdio.h>

int lower(int);

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

int lower(int c) { return c + ((c >= 'A' && c <= 'Z') ? 'a' - 'A' : 0); }

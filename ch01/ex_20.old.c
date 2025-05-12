#include <stdio.h>
#define TABSTOP 4

main() {
  int c;
  int state = 0;

  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      do {
        putchar(' ');
      } while ((++state) % TABSTOP != 0);
      continue;
    }

    if (c == '\n') {
      state = 0;
    } else {
      state++;
    }

    putchar(c);
  }
  return 0;
}

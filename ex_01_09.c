#include <stdio.h>

main() {
  int c, last;

  last = -1;
  while ((c = getchar()) != EOF) {
    if (c != ' ' || last != ' ')
      putchar(c);
    last = c;
  }
}

#include <stdio.h>
#define TABSTOP 4

main() {
  int c;
  int state = 0;
  int i = 0;

  /* TODO: handle c = '\t' (see solutions) */
  while ((c = getchar()) != EOF) {
    if (c == ' ' && ((++i + state) % TABSTOP) == 0) {
      putchar('\t');
      i = 0;
      state++;
    } else if (c != ' ') {
      /* print the remaining spaces that did not make a tabbstop */
      while (i > 0) {
        putchar(' ');
        state++;
        i--;
      }
      putchar(c);

      if (c == '\n')
        state = 0;
      else
        state++
    }
  }
  return 0;
}

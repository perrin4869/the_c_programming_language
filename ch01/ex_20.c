#include <stdio.h>

#define COLUMNS 10

main() {
  int col;
  int c;

  col = 0;
  while ((c = getchar()) != EOF)
    if (c == '\t') {
      putchar(' ');
      col++;
      while (col % COLUMNS != 0) {
        /* printf("%d %d", col, COLUMNS - (col % COLUMNS)); */
        putchar(' ');
        col++;
      }
    } else {
      putchar(c);
      col++;
      if (c == '\n')
        col = 0;
    }
}

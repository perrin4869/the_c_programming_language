#include <stdio.h>

#define COLUMNS 4

main() {
  int col;
  int space;
  int c;

  col = 0;
  space = 0;
  while ((c = getchar()) != EOF)
    if (c == ' ') {
      space++;
      if ((space + col) % COLUMNS == 0) {
        space = 0;
        putchar('\t');
      }
    } else if (c == '\t') {
      space = 0;
      col = col + (COLUMNS - col % COLUMNS);
      putchar(c);
    } else {
      while (space > 0) {
        putchar(' ');
        space--;
        col++;
      }
      putchar(c);

      if (c == '\n')
        col = 0;
      else
        col++;
    }
}

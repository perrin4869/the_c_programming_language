#include "settab.h"
#include <stdio.h>
#include <stdlib.h>

void detab(enum boolean tabs[]);

main(int argc, char *argv[]) {
  enum boolean tabs[MAXLINE + 1];

  settab(argc, argv, tabs);
  detab(tabs);
}

void detab(enum boolean tabs[]) {
  int col;
  int c;

  col = 1;
  while ((c = getchar()) != EOF)
    if (c == '\t') {
      do {
        putchar(' ');
      } while (col <= MAXLINE && !tabs[col++]);
    } else {
      putchar(c);
      col++;
      if (c == '\n')
        col = 1;
    }
}

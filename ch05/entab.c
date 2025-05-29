#include "settab.h"
#include <stdio.h>
#include <stdlib.h>

void entab(enum boolean tabs[]);

main(int argc, char *argv[]) {
  enum boolean tabs[MAXLINE + 1];

  settab(argc, argv, tabs);
  entab(tabs);
}

void entab(enum boolean tabs[]) {
  int col;
  int space;
  int c;

  col = 1;
  space = 0;
  while ((c = getchar()) != EOF)
    if (c == ' ') {
      /* printf("col: %d spaces: %d\n", col, space); */
      if (space + col > MAXLINE || tabs[space + col]) {
        putchar('\t');
        col += space + 1;

        space = 0;
      } else {
        space++;
      }
    } else if (c == '\t') {
      space = 0;
      while (col <= MAXLINE && !tabs[col++])
        ;
      putchar(c);
    } else {
      while (space > 0) {
        putchar(' ');
        col++;
        space--;
      }
      putchar(c);

      if (c == '\n')
        col = 1;
      else
        col++;
    }
}

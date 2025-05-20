#include "polish_calculator.h"
#include <ctype.h>
#include <stdio.h>

#define EMPTY -1

/* getop: get next operator or numeric operand */
int getop(char s[]) {
  static int ungetch = EMPTY;
  int i, c;

  while ((s[0] = c = (ungetch != EMPTY) ? ungetch : getchar()) == ' ' ||
         c == '\t')
    ungetch = EMPTY;

  s[1] = '\0';
  if (!isdigit(c) && c != '.')
    return c;
  i = 0;
  if (isdigit(c))
    while (isdigit(s[++i] = c = getchar()))
      ;

  if (c == '.')
    while (isdigit(s[++i] = c = getchar()))
      ;
  s[i] = '\0';
  ungetch = (c != EOF) ? c : EMPTY;
  return NUMBER;
}

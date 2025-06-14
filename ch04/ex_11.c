#include "polish_calculator.h"
#include <ctype.h>
#include <stdio.h>

/* getop: get next operator or numeric operand */
int getop(char s[]) {
  int i, c;
  static int buf = 0;

  s[0] = c = !buf ? getchar() : buf;
  buf = 0;
  while (c == ' ' || c == '\t')
    s[0] = c = getchar();

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
  if (c != EOF)
    buf = c;

  return NUMBER;
}

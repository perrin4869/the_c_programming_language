#include "../ch04/polish_calculator.h"
#include <ctype.h>
#include <stdio.h>

/* I think the point of this exercise is to demonstrate, scanf doesn't
 * necessarily make input reading easier ^^;
 * I think this half-baked solution serves to show how it is not possible to
 * implement without reading a character at a time */

/* getop: get next operator or numeric operand */
int getop(char s[]) {
  /* this doesn't work to detect a newline, so this function doesn't work */
  if (scanf("\n") == 1)
    return '\n';
  if (scanf("%s", s) == EOF)
    return EOF;
  if (sscanf(s, "%d") == 1)
    return NUMBER;
  return *s;
}

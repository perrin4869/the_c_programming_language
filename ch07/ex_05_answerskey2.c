#include "../ch04/polish_calculator.h"
#include <ctype.h>
#include <stdio.h>

/* getop: get next operator or numeric operand */
int getop(char s[]) {
  int c, rc;
  float f;

  while ((rc = scanf("%c", &c)) != EOF)
    if ((s[0] = c) != ' ' && c != '\t')
      break;
  s[1] = '\0';
  if (rc == EOF)
    return EOF;
  else if (!isdigit(c) && c != '.')
    return c;
  ungetc(c, stdin);
  scanf("%f", &f);
  sprintf(s, "%f", f);
  return NUMBER;
}

#include "../ch04/polish_calculator.h"
#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[]) {
  int c;

  while ((*s = c = getch()) == ' ' || c == '\t')
    ;

  *(s + 1) = '\0';
  if (!isdigit(c) && c != '.')
    return c;
  if (isdigit(c))
    while (isdigit(*++s = c = getch()))
      ;

  if (c == '.')
    while (isdigit(*++s = c = getch()))
      ;
  *s = '\0';
  if (c != EOF)
    ungetch(c);
  return NUMBER;
}

#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int);

int getint(int *pn);

main() {
  int n, res;
  while ((res = getint(&n)) != EOF)
    if (res > 0) {
      printf("%d\n", n);
    } else {
      printf("NaN");
    }
}

/* getint: get next integer from input into *pn */
int getint(int *pn) {
  int c, sign;

  while (isspace(c = getch())) /* skip whitespace */
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c); /* it's not a number */
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-')
    if (!isdigit(c = getch())) {
      ungetch(c); /* should check for EOF before like below */
      ungetch(sign < 0 ? '-' : '+');
      return 0; /* the answers key return the sign character to indicate this
                   very situation */
    }
  for (*pn = 0; isdigit(c); c = getch())
    *pn = 10 * *pn + (c - '0');
  *pn *= sign;
  if (c != EOF)
    ungetch(c);
  return c;
}

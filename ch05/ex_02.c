#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int);

/* the answerskey uses a float type for pf */
int getfloat(double *pf);

main() {
  double f;
  int res;
  while ((res = getfloat(&f)) != EOF)
    if (res > 0) {
      printf("%f\n", f);
    } else {
      printf("NaN");
    }
}

/* getfloat: get next floating point number from input into *pf */
int getfloat(double *pf) {
  /* the answerskey defines power as float */
  int c, sign, power;

  while (isspace(c = getch())) /* skip whitespace */
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c); /* it's not a number */
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-')
    c = getch();
  for (*pf = 0; isdigit(c); c = getch())
    *pf = 10.0 * *pf + (c - '0');
  if (c == '.')
    c = getch();
  for (power = 1; isdigit(c); c = getch()) {
    *pf = 10.0 * *pf + (c - '0');
    power *= 10;
  }
  *pf /= power;
  *pf *= sign;
  if (c != EOF)
    ungetch(c);
  return c;
}

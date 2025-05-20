#include <ctype.h>
#include <stdio.h>

double atof(char s[]);

main() {
  printf("1e3: %f\n", atof("1e3"));
  printf("32.5e-2: %f\n", atof("32.5e-2"));
}

double atof(char s[]) {
  double val, power;
  int i, sign;
  int e, esign;

  for (i = 0; isspace(s[i]); i++)
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');
  if (s[i] == '.')
    i++;
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }

  /* from here: */
  if (s[i] == 'e' || s[i] == 'E') {
    esign = (s[++i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
      i++;
    for (e = 0; isdigit(s[i]); i++)
      e = 10 * e + (s[i] - '0');
    /* printf("e: %d, esign: %d\n", e, esign); */
    while (e-- > 0) {
      if (esign > 0)
        power /= 10.0;
      else
        power *= 10.0;
    }
  }

  return sign * val / power;
}

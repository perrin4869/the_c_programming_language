#include <ctype.h>
#include <stdio.h>

double atof(char[]);

main() {
  printf("%g\n", atof("9.358"));
  printf("%g\n", atof("  \t-10.58"));
  printf("%g\n", atof("-10.58e-2"));
  printf("%g\n", atof("-10.58e2"));
}

double atof(char s[]) {
  double val, power;
  int i, sign, exp, esign, j;

  for (i = 0; isspace(s[i]); i++)
    ;

  sign = s[i] == '-' ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + s[i] - '0';
  if (s[i] == '.')
    i++;
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }
  if (s[i] == 'e') {
    esign = s[++i] == '-' ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
      i++;
    for (exp = 0; isdigit(s[i]); i++)
      exp = 10 * exp + s[i] - '0';
    for (j = 0; j < exp; j++) {
      power = (esign > 0) ? power * 10.0 : power / 10.0;
    }
  }
  return sign * val / power;
}

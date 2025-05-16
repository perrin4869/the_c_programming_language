#include <limits.h>
#include <stdio.h>
#include <string.h>

void itoa_orig(int n, char s[]);
void itoa(int n, char s[]);
void reverse(char s[]);

main() {
  char res[100];
  int n;

  n = 255;
  itoa(n, res);
  printf("255: %d = %s\n", n, res);

  n = INT_MIN;
  itoa(INT_MIN, res);
  printf("INT_MIN: %d = %s\n", n, res);

  n = INT_MIN;
  itoa_orig(n, res);
  printf("(orig) - INT_MIN: %d = %s\n", n, res);

  n = INT_MIN + 1;
  itoa_orig(n, res);
  printf("(orig) - INT_MIN + 1: %d = %s\n", n, res);
}

void itoa_orig(int n, char s[]) {
  int i, sign;

  if ((sign = n) < 0) /* record sign */
    n = -n;
  i = 0;
  do {                     /* generate digits in reverse order */
    s[i++] = n % 10 + '0'; /* get next digit */
  } while ((n /= 10) != 0); /* delete it */

  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

void itoa(int n, char s[]) {
  int i, sign;

  sign = 1;
  if (n < 0) /* record sign */
    sign = -1;
  i = 0;
  do {                              /* generate digits in reverse order */
    s[i++] = sign * (n % 10) + '0'; /* get next digit */
  } while ((n /= 10) != 0); /* delete it */

  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

void reverse(char s[]) {
  int i, j;
  char c;
  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

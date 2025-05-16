#include <limits.h>
#include <stdio.h>
#include <string.h>

void itoa(int n, char s[], int w);
void reverse(char s[]);

main() {
  char res[100];
  int n;

  n = 255;
  itoa(n, res, 3);
  printf("255: %d = %s\n", n, res);

  itoa(n, res, 4);
  printf("255: %d = %s\n", n, res);

  itoa(n, res, 5);
  printf("255: %d = %s\n", n, res);
}

void itoa(int n, char s[], int w) {
  int i, sign;

  if ((sign = n) < 0) /* record sign */
    n = -n;
  i = 0;
  do {                     /* generate digits in reverse order */
    s[i++] = n % 10 + '0'; /* get next digit */
  } while ((n /= 10) != 0); /* delete it */

  if (sign < 0)
    s[i++] = '-';

  while (i < w)
    s[i++] = ' ';

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

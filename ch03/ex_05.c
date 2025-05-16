#include <limits.h>
#include <stdio.h>
#include <string.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

main() {
  char res[100];
  int n;

  n = 255;
  itob(n, res, 2);
  printf("255: %d = %s\n", n, res);

  n = 256;
  itob(n, res, 2);
  printf("255: %d = %s\n", n, res);
}

void itob(int n, char s[], int b) {
  int i, sign;

  if ((sign = n) < 0) /* record sign */
    n = -n;
  i = 0;
  do {                    /* generate digits in reverse order */
    s[i++] = n % b + '0'; /* get next digit */
  } while ((n /= b) != 0); /* delete it */

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

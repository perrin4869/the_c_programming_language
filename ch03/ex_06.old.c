#include <limits.h>
#include <stdio.h>

#define MAXLINE 1000
#define abs(x) ((x) < 0 ? -(x) : (x))

void reverse(char s[]);
void itoa(int n, char s[], int w);

main() {
  char line[MAXLINE];

  itoa(15, line, 4);
  printf("%d: %s\n", 15, line);

  itoa(-15, line, 4);
  printf("%d: %s\n", 15, line);

  itoa(29, line, 6);
  printf("%d: %s\n", 29, line);

  itoa(INT_MIN, line, 6);
  printf("%d: %s\n", INT_MIN, line);
}

void reverse(char s[]) {
  int i, j;
  /* a more efficient solution is to swap characters, removing the need for a */
  /* tmp string */
  char tmp[MAXLINE];

  i = 0;
  while (s[i] != '\0') {
    tmp[i] = s[i];
    i++;
  }
  i--;
  if (tmp[i] == '\n') {
    i--;
  }
  for (j = 0; j <= i; j++) {
    s[j] = tmp[i - j]; /* -1 to ignore the newline at the end of tmp */
  }
  s[++j] = '\0';
}

void itoa(int n, char s[], int w) {
  int i, sign;

  sign = n;
  i = 0;
  do {
    s[i++] = abs(n % 10) + '0';
    w--;
  } while ((n /= 10) != 0);

  if (sign < 0) {
    s[i++] = '-';
    w--;
  }

  while (w > 0) {
    s[i++] = ' ';
    w--;
  }

  s[i] = '\0';
  reverse(s);
}

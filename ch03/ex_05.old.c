#include <limits.h>
#include <stdio.h>

#define MAXLINE 1000
#define abs(x) ((x) < 0 ? -(x) : (x))

void reverse(char s[]);
void itoa(int n, char s[]);
void itob(int n, char s[], int b);

main() {
  char line[MAXLINE];

  itob(15, line, 16);
  printf("%d: %s\n", 15, line);

  itob(15, line, 2);
  printf("%d: %s\n", 15, line);

  itob(-15, line, 2);
  printf("%d: %s\n", 15, line);

  itoa(29, line);
  printf("%d: %s\n", 29, line);

  itoa(INT_MIN, line);
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

void itoa(int n, char s[]) { itob(n, s, 10); }

void itob(int n, char s[], int b) {
  int i, sign;

  sign = n;
  i = 0;
  do {
    s[i] = abs(n % b);
    s[i] = s[i] + ((s[i] > 9) ? ('a' - 10) : '0');
    i++;
  } while ((n /= b) != 0);

  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

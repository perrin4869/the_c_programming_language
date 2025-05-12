#include <limits.h>
#include <stdio.h>

#define MAXLINE 1000
#define abs(x) ((x) < 0 ? -(x) : (x))

void reverse(char s[]);
void itoa_textbook(int n, char s[]);
void itoa(int n, char s[]);
void itoa_answerskey(int n, char s[]);

main() {
  printf("%u, %u\n", INT_MIN, -19);

  char line[MAXLINE];

  itoa_textbook(29, line);
  printf("textbook %d: %s\n", 29, line);

  itoa_textbook(-29, line);
  printf("textbook %d: %s\n", -29, line);

  itoa_textbook(INT_MIN, line);
  printf("textbook %d: %s\n", INT_MIN, line);

  itoa(29, line);
  printf("textbook %d: %s\n", 29, line);

  itoa(-29, line);
  printf("textbook %d: %s\n", -29, line);

  itoa(INT_MIN, line);
  printf("%d: %s\n", INT_MIN, line);

  itoa_answerskey(INT_MIN, line);
  printf("answers key %d: %s\n", INT_MIN, line);
}

void reverse(char s[]) {
  int i, j;
  // a more efficient solution is to swap characters, removing the need for a
  // tmp string
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
    s[j] = tmp[i - j]; // -1 to ignore the newline at the end of tmp
  }
  s[++j] = '\0';
}

void itoa_textbook(int n, char s[]) {
  int i, sign;

  if ((sign = n) < 0)
    n = -n;
  i = 0;

  do {
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);

  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

// -128 = 10000000 in two's complement representation
// the two's complement of this number is 10000000
// as an unsigned int, it represents 128
void itoa(int n, char s[]) {
  int i;
  unsigned int un;

  if (n >= 0)
    un = n;
  else
    un = (n == INT_MIN) ? INT_MIN : -n;
  i = 0;

  do {
    s[i++] = un % 10 + '0';
  } while ((un /= 10) > 0);

  if (n < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

// this is nice because it does not handle INT_MIN like a separate case
void itoa_answerskey(int n, char s[]) {
  int i, sign;

  sign = n;
  i = 0;
  do {
    s[i++] = abs(n % 10) + '0';
  } while ((n /= 10) != 0);

  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

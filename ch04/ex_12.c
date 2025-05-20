#include <stdio.h>
#include <string.h>

#define SIZE 100

void itoa(int n, char s[]);
int itoa_r(int n, char s[], int i);

void itoa_answerskey(int n, char s[]);

main() {
  int n;
  char s[SIZE];

  n = 123;
  itoa(n, s);
  printf("%d: %s\n", n, s);

  n = -123;
  itoa(n, s);
  printf("%d: %s\n", n, s);

  n = 123;
  itoa_answerskey(n, s);
  printf("%d: %s\n", n, s);

  n = -123;
  itoa_answerskey(n, s);
  printf("%d: %s\n", n, s);
}

/*
 * well, obviously changing the signature of the function was not an option, and
 * adding a helper function was not the intended method for this exercise, but I
 * hadn't considered at all the possibility of using a static variable
 */
void itoa(int n, char s[]) {
  int i = 0;
  if (n < 0) {
    n = -1 * n;
    s[i++] = '-';
  }

  itoa_r(n, s, i);
}

int itoa_r(int n, char s[], int i) {
  int j;
  if (n > 0) {
    j = itoa_r(n / 10, s, i + 1);
    s[j] = n % 10 + '0';
    return j + 1;
  } else {
    s[i] = '\0';
    return s[0] == '-' ? 1 : 0;
  }
}

void itoa_answerskey(int n, char buf[]) {
  static int i;

  if (n / 10)
    itoa_answerskey(n / 10, buf);
  else {
    i = 0;
    if (n < 0)
      buf[i++] = '-';
  }
  buf[i++] = abs(n) % 10 + '0';
  buf[i] = '\0';
}

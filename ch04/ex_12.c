#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void itoa(int, char[]);
void itoa_answerskey(int, char[]);

main() {
  char buf[MAX];

  itoa(4, buf);
  printf("%s\n", buf);
  itoa(103, buf);
  printf("%s\n", buf);
  itoa(1042, buf);
  printf("%s\n", buf);

  itoa_answerskey(4, buf);
  printf("%s\n", buf);
  itoa_answerskey(103, buf);
  printf("%s\n", buf);
  itoa_answerskey(1042, buf);
  printf("%s\n", buf);
  itoa_answerskey(-1042, buf);
  printf("%s\n", buf);
}

void itoa(int n, char buf[]) {
  static int i;
  if (n == 0) {
    int j, t;
    for (j = 0; j <= (i - 1) / 2; j++) {
      t = buf[j];
      buf[j] = buf[i - 1 - j];
      buf[i - 1 - j] = t;
    }
    buf[i] = '\0';
    i = 0;
  } else {
    buf[i++] = n % 10 + '0';
    itoa(n / 10, buf);
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

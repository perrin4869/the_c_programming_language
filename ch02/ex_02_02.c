#include <stdio.h>
#define LIM 1000

main() {
  int i, c;
  char s[LIM];
  for (i = 0; i < LIM - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
    s[i] = c;

  // without using && operator
  for (i = 0; i < LIM - 1; ++i) {
    if ((c = getchar()) == '\n') {
      break;
    } else if (c == EOF) {
      break;
    }
    s[i] = c;
  }
}

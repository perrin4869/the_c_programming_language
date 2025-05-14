#include <stdio.h>

main() {
  int i;
  int c;
  int lim;
  char s[20];

  for (i = 0; i < lim - 1; i++) {
    if ((c = getchar()) != '\n') {
      if (c != EOF) {
        s[i] = c;
      } else {
        break;
      }
    } else {
      break;
    }
  }

  /* from the answers key: */

  enum loop { NO, YES };
  enum loop okloop = YES;

  i = 0;
  while (okloop == YES) {
    if (i >= lim - 1)
      okloop = NO;
    else if ((c = getchar()) == '\n')
      okloop = NO;
    else if (c == EOF)
      okloop = NO;
    else {
      s[i] = c;
      ++i;
    }
  }
}

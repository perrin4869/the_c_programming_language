#include <stdio.h>

char buf = -1;

int getch(void) {
  if (buf > -1) {
    int c;
    c = buf;
    buf = -1;
    return c;
  }
  return getchar();
}

void ungetch(int c) {
  if (buf > -1)
    printf("ungetch: too many characters\n");
  else
    buf = c;
}

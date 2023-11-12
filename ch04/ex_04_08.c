#include <stdio.h>

#define EMPTY 0

char buf = EMPTY;

int getch(void) {
  int ret = (buf != EMPTY) ? buf : getchar();
  buf = EMPTY;
  return ret;
}
void ungetch(int c) {
  if (buf != EMPTY)
    printf("ungetch: too many characters\n");
  else
    buf = c;
}

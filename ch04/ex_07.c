#include <stdio.h>
#include <string.h>

int getch(void);
void ungetch(int);

void ungets(const char s[]);

main() {
  ungets("foo");
  int i;
  for (i = 0; i < 3; i++) {
    printf("%c", getch());
  }
  printf("\n");
}

void ungets(const char s[]) {
  int len;
  int i;

  len = strlen(s);
  for (i = len - 1; i >= 0; i--)
    ungetch(s[i]);
}

#include <stdio.h>

int getch(void);
void ungetch(int);

void ungets(const char s[]);

main() {
  ungets("foo");
  int i;
  for (i = 0; i < 3; i++) {
    printf("%c", getch());
  }
}

void ungets(const char s[]) {
  int i;
  for (i = 0; s[i] != '\0'; i++)
    ungetch(s[i]);
}

#include <stdio.h>

void ungetch(int);
void ungets(char[]);

// the scope of this solution is pretty narrow
main() {}

void ungets(char s[]) {
  int i;
  for (i = 0; s[i] != '\0'; i++) {
    ungetch(s[i]);
  }
}

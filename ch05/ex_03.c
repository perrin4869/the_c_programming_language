#include <stdio.h>

void strcat_sol(char *s, char *t);

main() {
  char a[50] = "foo";
  char *b = "bar";

  strcat_sol(a, b);
  printf("%s\n", a);
}

void strcat_sol(char *s, char *t) {
  while (*s++)
    ;
  s--;
  while ((*s++ = *t++))
    ;
}

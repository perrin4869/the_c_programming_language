#include <stdio.h>
#include <string.h>

int strrindex(const char s[], const char t[]);

main() {
  printf("strrindex(\"aa bb aa\", \"aa\"): %d\n", strrindex("aa bb aa", "aa"));
  printf("strrindex(\"ttabbaciibaid\", \"ba\"): %d\n",
         strrindex("ttabbaciibaid", "ba"));
}

int strrindex(const char s[], const char t[]) {
  int tl = strlen(t) - 1;
  int i, j;

  for (i = strlen(s) - 1; i >= tl; i--) {
    for (j = tl; j >= 0 && s[i - (tl - j)] == t[j]; j--)
      ;
    if (j == -1)
      return i - tl;
  }

  return -1;
}

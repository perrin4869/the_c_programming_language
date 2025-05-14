#include <stdio.h>

int any(const char s[], const char s2[]);

main() {
  printf("any(\"abc\", \"bc\"): %d\n", any("abc", "bc"));
  printf("any(\"xyz\", \"ef\"): %d\n", any("xyz", "ef"));
}

int any(const char s[], const char s2[]) {
  int i = 0;
  int j = 0;

  for (i = 0; s[i] != '\0'; i++) {
    for (j = 0; s2[j] != s[i] && s2[j] != '\0'; j++)
      ;
    if (s2[j] == s[i])
      return i;
  }

  return -1;
}

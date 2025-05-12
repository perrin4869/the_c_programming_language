#include <stdio.h>

#define SIZE 1000

void expand(char s1[], const char s2[]);

main() {
  char s[SIZE];
  expand(s, "a-z");
  printf("%s\n", s);

  expand(s, "-a-z");
  printf("%s\n", s);

  expand(s, "a-z-");
  printf("%s\n", s);

  expand(s, "0-9");
  printf("%s\n", s);
}

void expand(char s1[], const char s2[]) {
  int i, j;
  char k;
  for (i = 0, j = 0; s2[i] != '\0'; i++) {
    if (i > 0 && s2[i] == '-' && s2[i + 1] != '\0')
      for (k = s1[j - 1] + 1, ++i; k <= s2[i]; k++)
        s1[j++] = k;
    else
      s1[j++] = s2[i];
  }
  s1[j++] = '\0';
}

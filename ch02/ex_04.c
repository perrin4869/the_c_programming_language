#include <stdio.h>

void squeeze(char s[], const char s2[]);

main() {
  char s1[] = "abc";
  char s2[] = "xyz";

  squeeze(s1, "bc");
  squeeze(s2, "xyz");

  printf("%s\n", s1);
  printf("%s\n", s2);
}

void squeeze(char s[], const char s2[]) {
  int i = 0;
  int j = 0;
  int k = 0;

  for (i = j = 0; s[i] != '\0'; i++) {
    for (k = 0; s2[k] != s[i] && s2[k] != '\0'; k++)
      ;
    if (s2[k] == '\0')
      s[j++] = s[i];
  }

  s[j] = '\0';
}

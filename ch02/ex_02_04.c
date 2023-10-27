#include <stdio.h>

typedef enum boolean { FALSE, TRUE } boolean;

void squeeze(char[], const char[]);
boolean exists(const char[], char);

main() {
  char str1[] = "foo";
  squeeze(str1, "omg");
  printf("%s\n", str1);

  char str2[] = "let's try one last time";
  squeeze(str2, "omg");
  printf("%s\n", str2);
}

void squeeze(char s[], const char s2[]) {
  int i, j;
  for (i = 0, j = 0; s[i] != '\0'; i++) {
    if (!exists(s2, s[i]))
      s[j++] = s[i];
  }
  s[j++] = '\0';
}

boolean exists(const char s[], char c) {
  int i;
  for (i = 0; s[i] != '\0'; i++)
    if (s[i] == c)
      return TRUE;
  return FALSE;
}

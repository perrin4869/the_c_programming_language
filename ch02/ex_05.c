#include <stdio.h>

#define NOT_FOUND -1

typedef enum boolean { FALSE, TRUE } boolean;

int any(const char[], const char[]);
boolean exists(const char[], char);

main() {
  printf("%d\n", any("foo", "bar"));
  printf("%d\n", any("foo", "omg"));
  printf("%d\n", any("bar", "emgr"));
}

int any(const char s[], const char s2[]) {
  int i;
  for (i = 0; s[i] != '\0'; i++)
    if (exists(s2, s[i]))
      return i;
  return NOT_FOUND;
}

boolean exists(const char s[], char c) {
  int i;
  for (i = 0; s[i] != '\0'; i++)
    if (s[i] == c)
      return TRUE;
  return FALSE;
}

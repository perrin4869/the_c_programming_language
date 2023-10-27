#include <stdio.h>
#define MAXLINE 80

int mgetline(char line[], int maxline);

main() {
  int len;
  int c;
  char line[MAXLINE + 2]; // allow fitting 81 characters + the null character

  while ((len = mgetline(line, MAXLINE + 2)) > 0)
    if (len > MAXLINE) {
      printf("%s", line);
      while ((c = getchar()) != '\n') {
        putchar(c);
      }
      putchar(c);
    }
  return 0;
}

int mgetline(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

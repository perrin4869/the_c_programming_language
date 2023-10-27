#include <stdio.h>
#define MAXLINE 1000

int mgetline(char line[], int maxline);

main() {
  int len;
  char line[MAXLINE];
  int i;

  while ((len = mgetline(line, MAXLINE)) > 0) {
    // find the length without the trailing chars
    len--; // ignore the null character
    while (len >= 0 &&
           (line[len] == ' ' || line[len] == '\t' || line[len] == '\n'))
      len--;
    if (len > 0) {
      line[len + 1] = '\0';
      printf("%s\n", line);
    }
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

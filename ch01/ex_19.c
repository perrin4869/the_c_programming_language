#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void reverse(char s[]);

main() {
  int len;
  char line[MAXLINE];
  int i;

  while ((len = getline(line, MAXLINE)) > 0) {
    reverse(line);
    printf("%s", line);
  }
  return 0;
}

int getline(char s[], int lim) {
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

void reverse(char s[]) {
  int len, i;
  char tmp;

  for (len = 0; s[len] != '\0'; len++)
    ;
  len--;
  if (s[len] == '\n')
    len--;
  for (i = 0; i < len - i; i++) {
    tmp = s[i];
    s[i] = s[len - i];
    s[len - i] = tmp;
  }
}

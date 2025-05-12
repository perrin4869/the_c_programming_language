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
  int i, j;
  /* a more efficient solution is to swap characters, removing the need for a */
  /* tmp string */
  char tmp[MAXLINE];

  i = 0;
  while (s[i] != '\0') {
    tmp[i] = s[i];
    i++;
  }
  i--;
  if (tmp[i] == '\n') {
    i--;
  }
  for (j = 0; j <= i; j++) {
    s[j] = tmp[i - j]; /* -1 to ignore the newline at the end of tmp */
  }
  s[++j] = '\0';
}

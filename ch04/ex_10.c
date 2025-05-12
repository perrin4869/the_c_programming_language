#include "polish_calculator.h"
#include <ctype.h>
#include <stdio.h>

#define MAXLINE 1000

int li;
char line[1000];

int mgetline(char[], int);

/* getop: get next operator or numeric operand */
int getop(char s[]) {
  int l;
  if (line[li] == '\0') {
    l = mgetline(line, MAXLINE);
    li = 0;
    if (l < 1)
      return EOF;
  }

  int i, c;
  while ((s[0] = c = line[li++]) == ' ' || c == '\t')
    ;

  s[1] = '\0';
  if (!isdigit(c) && c != '.')
    return c;
  i = 0;
  if (isdigit(c))
    while (isdigit(s[++i] = c = line[li++]))
      ;

  if (c == '.')
    while (isdigit(s[++i] = c = line[li++]))
      ;
  s[i] = '\0';
  li--; // was forgetting this, ungetch
  return NUMBER;
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

  if (c != '\n' && c != EOF) {
    while ((c = getchar()) != EOF && c != '\n') {
      ++i;
    }
    if (c == '\n')
      ++i;
  }
  return i;
}

#include "polish_calculator.h"
#include <ctype.h>
#include <stdio.h>

#define MAXLINE 100

int getline(char line[], int maxline);

/*
 * do not declare as static, because that is not discussed until page 83 of K&R
 */
int i;
char line[MAXLINE];

/* getop: get next operator or numeric operand */
int getop(char s[]) {
  int j, c;

  /*
   * note: it suffices to check line[i] == '\0'
   * this is because an external variable is initialized to 0, i.e,
   * int line[MAXLINE] = {0}
   * so the case where this is the first call to getop folds into the case where
   * we are at the end of the current line
   * taken from the answers key
   */
  if (i == 0 || line[i] == '\0') {
    if (!getline(line, MAXLINE))
      return EOF;
    i = 0;
  }

  while ((s[0] = c = line[i++]) == ' ' || c == '\t')
    ;

  s[1] = '\0';
  if (!isdigit(c) && c != '.')
    return c;
  j = 0;
  if (isdigit(c))
    while (isdigit(s[++j] = c = line[i++]))
      ;

  if (c == '.')
    while (isdigit(s[++j] = c = line[i++]))
      ;
  s[j] = '\0';
  i--;
  return NUMBER;
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

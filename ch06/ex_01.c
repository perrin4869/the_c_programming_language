#include <ctype.h>
#include <stdio.h>

void skip_to_end_of_comment();
void skip_to_end_of_quote(int);
void skip_to_end_of_preprocessor();

/* getword: get next word or character from input */
int getword(char *word, int lim) {
  int c, getch(void);
  void ungetch(int);
  char *w = word;
  int d;

  while (isspace(c = getch()))
    ;
  if (c == '/') {
    if ((d = getch()) == '*') {
      skip_to_end_of_comment();
      return getword(word, lim);
    } else
      ungetch(d);
  } else if (c == '"' || c == '\'') {
    skip_to_end_of_quote(c);
    return getword(word, lim);
  } else if (c == '#') {
    skip_to_end_of_preprocessor();
    return getword(word, lim);
  }

  if (c != EOF)
    *w++ = c;
  if (!isalpha(c)) {
    *w = '\0';
    return c;
  }
  for (; --lim > 0; w++)
    if (!isalnum(*w = getch()) && *w != '_') {
      ungetch(*w);
      break;
    }
  *w = '\0';
  return word[0];
}

void skip_to_end_of_comment() {
  int c, d;
  c = getch();
  d = getch();
  while ((c != '*' || d != '/') && d != EOF) {
    c = d;
    d = getch();
  }
}

void skip_to_end_of_quote(int q) {
  int c;
  while ((c = getch()) != q && c != EOF)
    if (c == '\\')
      getch();
}

void skip_to_end_of_preprocessor() {
  int c, d;
  for (c = getch(), d = getch(); c != '\n' || d == '\\'; d = c, c = getch())
    ;
}

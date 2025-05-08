#include <stdio.h>

#define LINE 50
#define TAB 8

int getword(char s[], int l);

/* better than the old solution, still not as good as the one in the answers
 * key */
/* this doesn't handle properly a space at the end of a line */
main() {
  int col;
  int len;
  char word[LINE];

  col = 0;
  while ((len = getword(word, LINE)) != 0) {
    if (len + col > LINE) {
      printf("\n%s", word);
      col = len;
    } else {
      printf("%s", word);
    }

    if (word[len - 1] == '\n')
      col = 0;
    else
      col = col + len;

    if (word[len - 1] == '\t')
      col = col + TAB - 1;
  }
}

int getword(char s[], int l) {
  int i, c;

  for (i = 0; i < l - 1 && (c = getchar()) != ' ' && c != '\t' && c != '\n' &&
              c != EOF;
       i++)
    s[i] = c;
  if (c == ' ' || c == '\t' || c == '\n')
    s[i++] = c;
  s[i] = '\0';

  return i;
}

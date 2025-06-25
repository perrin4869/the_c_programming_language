#include "../ch04/polish_calculator.h"
#include <ctype.h>
#include <stdio.h>

/* getop: get next operator or numeric operand */
int getop(char s[]) {
  int c, i, rc;
  static char lastc[] = " ";

  /* fix: this is not present in the answers key
   * in my x86_64 PC, c may be initialized to a garbage value, which has bits
   * set beyond the first byte
   * scanf doesn't touch the bits beyond the first byte, and c ends up having a
   * value such as 32544. Uncomment the following to observe: */
  /* printf("c: %d\n", c); */
  c = 0;

  sscanf(lastc, "%c", &c);
  lastc[0] = ' '; /* clear last character */
  while ((s[0] = c) == ' ' || c == '\t')
    if (scanf("%c", &c) == EOF)
      c = EOF;
  s[1] = '\0';
  if (!isdigit(c) && c != '.')
    return c; /* not a number */
  i = 0;
  if (isdigit(c)) /* collect integer part */
    do {
      rc = scanf("%c", &c);
      if (!isdigit(s[++i] = c))
        break;
    } while (rc != EOF);
  if (c == '.') /* collect fraction part */
    do {
      rc = scanf("%c", &c);
      if (!isdigit(s[++i] = c))
        break;
    } while (rc != EOF);
  s[i] = '\0';
  if (rc != EOF)
    lastc[0] = c;
  return NUMBER;
}

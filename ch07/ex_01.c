#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strend(char *s, char *t);

main(int argc, char *argv[]) {
  int c;
  int (*conv)(int);

  if (strend(argv[0], "upper"))
    conv = toupper;
  else if (strend(argv[0], "lower"))
    conv = tolower;
  else {
    printf("must be named either 'upper' or 'lower'\n");
    exit(1);
  }

  while ((c = getchar()) != EOF)
    putchar(conv(c));
  return 0;
}

/* ch05: ex_04 */
/* strend: return 1 if string t occurs at the end of s */
int strend(char *s, char *t) {
  char *bs = s; /* remembering the beginning of the strs */
  char *bt = t;

  for (; *s; s++) /* at the end of the string s */
    ;
  for (; *t; t++) /* at the end of the string t */
    ;
  for (; *s == *t; s--, t--)
    if (bs == s || bt == t)
      break; /* at the beginning of a str */

  if (*s == *t && bt == t && *s != '\0')
    return 1;
  else
    return 0;
}

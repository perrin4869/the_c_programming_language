#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 100

main() {
  int c;
  int count;

  count = 0;
  while ((c = getchar()) != EOF) {
    if (isprint(c) || isspace(c))
      count += printf("%c", c);
    else
      count += printf("0x%x", c);

    if (count >= MAXLINE)
      printf("\n");
    if (c == '\n' || count >= MAXLINE)
      count = 0;
  }
}

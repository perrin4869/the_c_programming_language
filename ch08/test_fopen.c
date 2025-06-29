#include "stdio.h"

FILE *fopen(const char *name, const char *mode);
int printf(const char *, ...);

main() {
  FILE *fp;
  int c;

  if ((fp = fopen("input.txt", "r")) == NULL) {
    printf("failed to open foo.");
    return 1;
  };
  while ((c = getc(fp)) != EOF)
    printf("%c", c);
  return 0;
}

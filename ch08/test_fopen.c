#include "stdio.h"

FILE *fopen(const char *name, const char *mode);
int printf(const char *, ...);

main() {
  FILE *fp;
  char *name = "input.txt";
  int c;

  if ((fp = fopen(name, "r")) == NULL) {
    printf("failed to open %s.", name);
    return 1;
  };
  while ((c = getc(fp)) != EOF)
    printf("%c", c);
  return 0;
}

#include "stdio.h"

FILE *fopen(const char *name, const char *mode);
int printf(const char *, ...);

main() {
  FILE *fp;
  int c;
  char *name = "output.txt";
  char *output = "my output";

  if ((fp = fopen(name, "w")) == NULL) {
    printf("failed to open %s.", name);
    return 1;
  };
  while (c = (unsigned char)*output++)
    if (putc(c, fp) == EOF) {
      printf("error writing");
      return 1;
    }
  fclose(fp);
  return 0;
}

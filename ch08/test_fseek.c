#include "stdio.h"

FILE *fopen(const char *name, const char *mode);
int fseek(FILE *fp, long offset, int origin);
int printf(const char *, ...);

main() {
  FILE *fp;
  int c;
  char *name = "output.txt";
  char *output = "foo bar";
  char *output2 = "baz\n";

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
  if ((fp = fopen(name, "a")) == NULL) {
    printf("failed to open %s.", name);
    return 1;
  };
  if (fseek(fp, 4, 0) == EOF) {
    printf("failed to fseek");
    return 1;
  }
  while (c = (unsigned char)*output2++)
    if (putc(c, fp) == EOF) {
      printf("error writing");
      return 1;
    }
  fclose(fp);

  return 0;
}

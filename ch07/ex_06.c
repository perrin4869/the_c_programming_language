#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 100

main(int argc, char *argv[]) {
  int n, cmp;
  FILE *fp1, *fp2;
  char line1[MAXLINE], line2[MAXLINE];
  char *rt1, *rt2;

  if (argc != 3) {
    printf("usage: %s <file1> <file2>\n", argv[0]);
    exit(1);
  }

  fp1 = fopen(argv[1], "r");
  fp2 = fopen(argv[2], "r");

  n = 1;
  do {
    rt1 = fgets(line1, MAXLINE, fp1);
    rt2 = fgets(line2, MAXLINE, fp2);
    if (rt1 != NULL && rt2 != NULL)
      if ((cmp = strcmp(line1, line2)) == 0)
        n++;
      else
        break;
  } while (rt1 != NULL && rt2 != NULL);

  if (ferror(fp1)) {
    printf("error: %s encountered a read error\n", argv[1]);
    exit(2);
  }
  if (ferror(fp2)) {
    printf("error: %s encountered a read error\n", argv[2]);
    exit(2);
  }

  fclose(fp1);
  fclose(fp2);

  if (rt1 == NULL && rt2 == NULL)
    printf("the files are equal\n");
  else
    printf("the files differ on line %d\n", n);

  return 0;
}

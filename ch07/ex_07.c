#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXFILES 100
#define MAXLINE 1000

/* find: print lines that match pattern from 1st arg */
main(int argc, char *argv[]) {
  char line[MAXLINE];
  long lineno = 0;
  int i, c, except = 0, number = 0, found = 0;
  char *pattern;
  FILE *files[MAXFILES];

  while (--argc > 0 && (*++argv)[0] == '-')
    while (c = *++argv[0])
      switch (c) {
      case 'x':
        except = 1;
        break;
      case 'n':
        number = 1;
        break;
      default:
        printf("find: illegal option %c\n", c);
        argc = 0;
        found = -1;
        break;
      }

  if (argc < 1)
    printf("Usage: find -x -n pattern <file1> <file2> ...\n");
  else {
    pattern = *argv++;

    if (argc == 1)
      files[0] = stdin;
    else {
      argc--;
      for (i = 0; i < argc; i++)
        if ((files[i] = fopen(argv[i], "r")) == NULL) {
          fprintf(stderr, "failed to open file %s\n", argv[i]);
          exit(1);
        };
    }

    for (i = 0; i < argc; i++) {
      lineno = 0;
      while (fgets(line, MAXLINE, files[i]) != NULL) {
        lineno++;
        if ((strstr(line, pattern) != NULL) != except) {
          if (files[i] != stdin)
            printf("%s: ", argv[i]);
          if (number)
            printf("%ld:", lineno);
          printf("%s", line);
          found++;
        }
      }
      fclose(files[i]);
    }
  }
  return found;
}

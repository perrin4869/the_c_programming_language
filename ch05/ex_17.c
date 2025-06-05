#include <ctype.h>
#include <stdio.h>

#define NUMERIC 1 /* numeric sort */
#define DECR 2    /* sort in decreasing order */
#define FOLD 4    /* ignore case */
#define DIR 8     /* directory order */
#define LINES 100 /* max # of lines to be sorted */

int charcmp(char *, char *);
void error(char *);
int numcmp(char *, char *);
void readargs(int argc, char *argv[]);
int readlines(char *lineptr[], int nlines);
void qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
void writelines(char *lineptr[], int nlines, int decr);

char option = 0;
int pos1 = 0; /* field beginning with pos1 */
int pos2 = 0; /* ending just before pos2 */

/* sort input lines */
main(int argc, char *argv[]) {
  char *lineptr[LINES]; /* pointers to text lines */
  int nlines;           /* number of input lines read */
  int rc = 0;

  readargs(argc, argv);
  if ((nlines = readlines(lineptr, LINES)) > 0) {
    if (option & NUMERIC)
      qsort((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))numcmp);
    else
      qsort((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))charcmp);
    writelines(lineptr, nlines, option & DECR);
    return 0;
  } else {
    printf("error: input too big to sort\n");
    rc = -1;
  }

  return rc;
}

/* readargrs: read program arguments */
void readargs(int argc, char *argv[]) {
  int c;
  int atoi(char *);

  while (--argc > 0 && (c = (*++argv)[0]) == '-' || c == '+')
    if (c == '-' && !isdigit(*(argv[0] + 1)))
      while (c = *++argv[0])
        switch (c) {
        case 'n': /* numeric sort */
          option |= NUMERIC;
          break;
        case 'r': /* sort in decr. order */
          option |= DECR;
          break;
        case 'f': /* fold upper and lower */
          option |= FOLD;
          break;
        case 'd': /* directory order */
          option |= DIR;
          break;
        default:
          printf("sort: illegal option %c\n", c);
          error("Usage: sort -dfnr [+pos1] [-pos2]");
          break;
        }
    else if (c == '-')
      pos2 = atoi(argv[0] + 1);
    else if ((pos1 = atoi(argv[0] + 1)) < 0)
      error("Usage: sort -dfnr [+pos1] [-pos2]");

  if (argc || pos1 > pos2)
    error("Usage: sort -dfnr [+pos1] [-pos2]");
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines, int decr) {
  int i;

  if (decr) /* print in decreasing order */
    for (i = nlines - 1; i >= 0; i--)
      printf("%s\n", lineptr[i]);
  else
    for (i = 0; i < nlines; i++)
      printf("%s\n", lineptr[i]);
}

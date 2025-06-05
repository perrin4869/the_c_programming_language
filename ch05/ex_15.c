#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define NUMERIC 1 /* numeric sort */
#define DECR 2    /* sort in decreasing order */
#define FOLD 4    /* ignore case */
#define LINES 100 /* max # of lines to be sorted */

int numcmp(const char *, const char *);
int strcmp_fold(const char *, const char *);
int readlines(char *lineptr[], int nlines);
void qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
void writelines(char *lineptr[], int nlines, int decr);

static char option = 0;

/* sort input lines */
main(int argc, char *argv[]) {
  char *lineptr[LINES]; /* pointers to text lines */
  int nlines;           /* number of input lines read */
  int c, rc = 0;

  while (--argc > 0 && (*++argv)[0] == '-')
    while (c = *++argv[0])
      switch (c) {
      case 'n': /* numeric sort */
        option |= NUMERIC;
        break;
      case 'r': /* decreasing order */
        option |= DECR;
        break;
      case 'f': /* ignore case */
        option |= FOLD;
        break;
      default:
        printf("sort: illegal option %c\n", c);
        argc = 1;
        rc = -1;
        break;
      }

  if (argc)
    printf("Usage: sort -fnr\n");
  else if ((nlines = readlines(lineptr, LINES)) > 0) {
    if (option & NUMERIC)
      qsort((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))numcmp);
    else if (option & FOLD)
      qsort((void **)lineptr, 0, nlines - 1,
            (int (*)(void *, void *))strcmp_fold);
    else
      qsort((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))strcmp);
    writelines(lineptr, nlines, option & DECR);
    return 0;
  } else {
    printf("error: input too big to sort\n");
    rc = -1;
  }

  return rc;
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

int strcmp_fold(const char *s1, const char *s2) {
  char c1, c2;
  for (; *s1 && *s2 && (c1 = tolower(*s1)) == (c2 = tolower(*s2)); s1++, s2++)
    ;

  return c1 - c2;
}

/* this is the function used in the answers key to compare ignoring case: */
/* charcmp: return <0 if s<t, 0 if s==t, >0 if s>t*/
int charcmp(char *s, char *t) {
  for (; tolower(*s) == tolower(*t); s++, t++)
    if (*s == '\0')
      return 0;

  return tolower(*s) - tolower(*t);
}

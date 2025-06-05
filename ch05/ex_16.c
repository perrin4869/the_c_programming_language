#include <ctype.h>
#include <stdio.h>

#define NUMERIC 1 /* numeric sort */
#define DECR 2    /* sort in decreasing order */
#define FOLD 4    /* ignore case */
#define DIR 8     /* directory order */
#define LINES 100 /* max # of lines to be sorted */

int numcmp(const char *, const char *);
int charcmp(char *, char *);
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
      case 'd': /* ignore case */
        option |= DIR;
        break;
      default:
        printf("sort: illegal option %c\n", c);
        argc = 1;
        rc = -1;
        break;
      }

  if (argc)
    printf("Usage: sort -dfnr\n");
  else if ((nlines = readlines(lineptr, LINES)) > 0) {
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

#ifdef ANSWERSKEY
int charcmp(char *s, char *t) {
  char a, b;
  int fold = (option & FOLD) ? 1 : 0;
  int dir = (option & DIR) ? 1 : 0;

  do {
    if (dir) {
      while (!isalnum(*s) && *s != ' ' && *s != '\0')
        s++;
      while (!isalnum(*t) && *t != ' ' && *t != '\0')
        t++;
    }
    a = fold ? tolower(*s) : *s;
    s++;
    b = fold ? tolower(*t) : *t;
    t++;
    if (a == b && a == '\0')
      return 0;
  } while (a == b);
  return a - b;
}
#endif

#ifndef ANSWERSKEY
/* not a good solution - it should skip symbol characters completely */
/* this function fails when it compares a symbol and a non-symbol */
/* charcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int charcmp(char *s, char *t) {
  int normalize(char c);

  for (; normalize(*s) == normalize(*t); s++, t++)
    if (*s == '\0')
      return 0;

  return normalize(*s) - normalize(*t);
}

int normalize(char c) {
  if (option & DIR && !isalnum(c) && !isspace(c))
    return -1;

  if (option & FOLD)
    return tolower(c);

  return c;
}
#endif

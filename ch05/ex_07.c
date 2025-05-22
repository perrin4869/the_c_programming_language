#include <stdio.h>
#include <string.h>

#define MAXLINES 5000  /* max #lines to be sorted */
#define MAXSTORE 10000 /* max #lines to be sorted */

char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[], char *store, int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

/* sort input lines */
main() {
  int nlines; /* number of input lines read */
  char store[MAXSTORE];

  if ((nlines = readlines(lineptr, store, MAXLINES)) >= 0) {
    qsort(lineptr, 0, nlines - 1);
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("error: input too big to sort\n");
    return 1;
  }
}

#define MAXLEN 1000 /* max length of any input line */
int getline(char *, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], char *store, int maxlines) {
  int lines; /* number of input lines read */

  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  p = store;
  while ((len = getline(line, MAXLEN)) > 0)
    if (nlines >= maxlines || store + MAXSTORE - p < len)
      return -1;
    else {
      line[len - 1] = '\0'; /* delete newline */
      strcpy(p, line);
      lineptr[nlines++] = p;
      p += len;
    }
  return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines) {
  int i;

  for (i = 0; i < nlines; i++)
    printf("%s\n", lineptr[i]);
}

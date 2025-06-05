#include <stdio.h>
#include <string.h>

#define MAXLINES 5000    /* max #lines to be sorted */
char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(const char *, const char *);
void reverse(char *lines[], int nlines);

/* sort input lines */
main(int argc, char *argv[]) {
  int nlines;      /* number of input lines read */
  int numeric = 0; /* 1 if numeric sort */
  int rev = 0;     /* 1 if reverse sort */

  while (--argc > 0) {
    if (**++argv == '-') {
      switch (*++argv[0]) {
      case 'n':
        numeric = 1;
        break;
      case 'r':
        rev = 1;
        break;
      default:
        printf("unknown option %c\n", *argv[0]);
        break;
      }
    }
  }
  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    qsort((void **)lineptr, 0, nlines - 1,
          (int (*)(void *, void *))(numeric ? numcmp : strcmp));
    if (rev)
      reverse(lineptr, nlines);

    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("error: input too big to sort\n");
    return 1;
  }
}

void reverse(char *lines[], int nlines) {
  int i;
  char *temp;

  for (i = 0, nlines--; i < nlines; i++, nlines--) {
    temp = lines[i];
    lines[i] = lines[nlines];
    lines[nlines] = temp;
  }
}

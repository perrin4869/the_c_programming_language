#include "settab.h"

void settab(int argc, char *argv[], enum boolean tabs[]) {
  int n, i;
  if (argc <= 1) {
    for (i = 1; i <= MAXLINE; i++) {
      tabs[i] = i % TABLEN == 0 ? TRUE : FALSE;
    }
  } else {
    for (i = 1; i <= MAXLINE; i++) {
      tabs[i] = FALSE;
    }
    while (--argc > 0) {
      n = atoi(*++argv);
      if (n > 0 && n <= MAXLINE) {
        tabs[n] = TRUE;
      }
    }
  }
}

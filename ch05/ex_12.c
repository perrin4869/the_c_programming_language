#include "settab.h"

#ifndef ESETTAB
void settab(int argc, char *argv[], enum boolean tabs[]) {
  int n = TABLEN, m = TABLEN, i;

  while (--argc > 0) {
    i = atoi(*++argv);
    if (i > 0)
      n = i;
    else if (i < 0)
      m = -1 * i;
  }

  for (i = 1; i < m; i++)
    tabs[i] = FALSE;
  for (; i <= MAXLINE; i++) {
    tabs[i] = (i - m) % TABLEN == 0 ? TRUE : FALSE;
  }
}
#endif

/*
 * this is the solution from the answers key
 * this one builds on the solution from the previous exercise
 */
#ifdef ESETTAB
void settab(int argc, char *argv[], enum boolean tabs[]) {
  int i, inc, pos;

  if (argc <= 1) /* default tab stops */
    for (i = 1; i <= MAXLINE; i++)
      if (i % TABLEN == 0)
        tabs[i] = TRUE;
      else
        tabs[i] = FALSE;
  else if (argc == 3 && /* user provided range */
           *argv[1] == '-' && *argv[2] == '+') {
    pos = atoi((*++argv) + 1);
    inc = atoi((*++argv) + 1);
    /* from the answers key */
    /* pos = atoi(&(*++argv)[1]); */
    /* inc = atoi(&(*++argv)[1]); */
    for (i = 1; i <= MAXLINE; i++)
      if (i != pos)
        tabs[i] = FALSE;
      else {
        tabs[i] = TRUE;
        pos += inc;
      }
  } else { /* user provided tab stops */
    for (i = 1; i <= MAXLINE; i++)
      tabs[i] = FALSE;   /* turn off all tab stops */
    while (--argc > 0) { /* walk through argument list */
      pos = atoi(*++argv);
      if (pos > 0 && pos <= MAXLINE)
        tabs[pos] = TRUE;
    }
  }
}
#endif

#include <stdio.h>

#define IN 0
#define OUT 1

#define MAX 50

main() {
  int c, state;
  int l[MAX], i, j;

  for (i = 0; i < MAX; i++) {
    l[i] = 0;
  }

  state = OUT;
  while ((c = getchar()) != EOF) {
    if (c != ' ' && c != '\t' && c != '\n') {
      ++state;
    } else if (state != 0) {
      ++l[state];
      state = 0;
    }
  }

  for (i = 0; i < MAX; i++) {
    printf("%2d: ", i);
    for (j = 0; j < l[i]; j++)
      putchar('#');
    printf("\n");
  }
}

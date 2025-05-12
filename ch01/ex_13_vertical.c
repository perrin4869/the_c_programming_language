#include <stdio.h>

#define MAX 50

main() {
  int c, state, max_state;
  int l[MAX], i, j;

  for (i = 0; i < MAX; i++) {
    l[i] = 0;
  }

  max_state = state = 0;
  while ((c = getchar()) != EOF) {
    if (c != ' ' && c != '\t' && c != '\n') {
      ++state;
    } else if (state != 0) {
      ++l[state];
      if (state > max_state)
        max_state = state;
      state = 0;
    }
  }

  for (i = 0; i < max_state; i++)
    printf("%3d", i);
  printf("\n");
  for (i = 0; i < max_state; i++) {
    for (j = 0; j < max_state; j++)
      if (--l[j + 1] >= 0)
        printf("  #");
      else
        printf("   ");
    printf("\n");
  }
}

#include <ctype.h>
#include <stdio.h>

#define CHARS 128
#define HIST_LENGTH 200

main() {
  int c, state, max_length;
  int l[CHARS], i, j;

  for (i = 0; i < CHARS; i++) {
    l[i] = 0;
  }

  max_length = state = 0;
  while ((c = getchar()) != EOF) {
    if (isprint(c))
      ++l[c];

    if (l[c] > max_length)
      max_length = l[c];
  }

  for (i = 0; i < CHARS; i++) {
    if (isprint(i)) {
      printf("%3d - %c = %3d: ", i, i, l[i]);
      for (j = 0; j < l[i] * HIST_LENGTH / max_length; j++)
        putchar('#');
      printf("\n");
    }
  }
}

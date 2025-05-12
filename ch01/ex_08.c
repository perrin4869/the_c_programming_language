#include <stdio.h>

main() {
  int c, nl, tabs, blanks;

  nl = 0;
  tabs = 0;
  blanks = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\n')
      ++nl;
    if (c == '\t')
      ++tabs;
    if (c == ' ')
      ++blanks;
  }
  printf("new lines: %d\n", nl);
  printf("blanks: %d\n", blanks);
  printf("tabs: %d\n", tabs);
}

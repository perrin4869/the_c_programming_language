#include <stdio.h>

#define NORMAL 0
#define STRING 1
#define COMMENT 2

/* again, not the most elegant but it works and is shorter lol
 * the old solution was closer to the one in the answers key
 * it also handled // comments
 * */
main() {
  int c, changing, lc;
  int state;

  state = NORMAL;
  changing = 0;
  lc = '\0';
  while ((c = getchar()) != EOF) {
    if (state == NORMAL && c == '"' && lc != '\'') {
      state = STRING;
    } else if (state == STRING && c == '"' && lc != '\\') {
      state = NORMAL;
    } else if (state == NORMAL && c == '/') {
      changing = 1;
    } else if (state == NORMAL && changing) {
      if (c == '*')
        state = COMMENT;
      else {
        putchar('/');
      }
      changing = 0;
    } else if (state == COMMENT && c == '*') {
      changing = 1;
    } else if (state == COMMENT && changing) {
      if (c == '/')
        state = NORMAL;
      changing = 0;
    }

    /* uncomment the following to test it works: */
    /* printf("thth\"thth"); */

    if (state != COMMENT &&
        !(state == NORMAL && changing) &&           /* maybe entering comment */
        !(state == NORMAL && lc == '*' && c == '/') /* left comment */
    )
      putchar(c);
    lc = c;
  }
}

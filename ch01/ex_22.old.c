#include <stdio.h>
#define BUFSIZE 100
#define MAXLINE 20

/*
 * not a very good solution compared to the one in the answer keys
 * this approach makes it harder to account for edge cases like handling
 * multiple spaces correctly, no tab handling, word overflow, etc
 * the better approach is to read lines into a buffer and print them once they
 * overflow or encounter a newline
 */
main() {
  int c;
  int pos = 0;
  int i = 0;
  char buf[BUFSIZE];

  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      buf[i++] = '\0';
      /* account for the trailing space */
      if (i + pos + 1 > MAXLINE) {
        if (pos == 0) {
          printf("%s\n", buf);
        } else {
          printf("\n%s", buf);
          pos += i;
        }
      } else {
        printf(" %s\n", buf);
        pos = 0;
      }
      i = 0;
    } else if (c == ' ') {
      buf[i++] = '\0';
      if (i + pos + 1 > MAXLINE) {
        printf("\n");
        pos = 0;
      } else if (pos > 0) {
        printf(" ");
        pos++;
      }
      printf("%s", buf);
      pos += i;
      i = 0;
    } else {
      buf[i++] = c;
    }
  }
  return 0;
}

#include <stdio.h>

#define BUFSIZE 100
/* the solution: char -> int */
int buf[BUFSIZE];
int bufp = 0;

/*
 * the definition from stdio.h
 * #define EOF (-1)
 */

/*
 * this is copied from the answers key because I couldn't figure it out
 * the pain point is storing -1 (0xFFFFFFFF) inside a char will convert
 * it into 0xFF, and converting it back into int is architecture dependent
 * (k&r page 43, depends on whether or not char is signed or unsigned)
 * negative number (-1) -> character ->   integer
 *      0xFFFF                0xFF      0x00FF (255)
 *      0xFFFF                0xFF      0xFFFF (-1)
 */
int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }
void ungetch(int c) {
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}

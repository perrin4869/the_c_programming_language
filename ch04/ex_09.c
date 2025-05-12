#include <stdio.h>

#define BUFSIZE 100
int buf[BUFSIZE];
int bufp = 0;

// this is copied from the answers key because I couldn't figure it out
// the pain point is storing -1 (0xFFFFFFFF) inside a char will convert
// it into 0xFF, and converting it back into int is architecture dependent
// (k&r page 43, depends on whether or not char is signed or unsigned)
// converting the char back into an int can either return 0xFFFFFFFF (if it was
// signed) or simply extend it by adding zeroes to the end 0x000000FF
// EOF is defined as -1
int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }
void ungetch(int c) {
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}

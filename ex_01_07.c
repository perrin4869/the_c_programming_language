#include <stdio.h>

main() {
  printf("putchar(EOF): ");
  putchar(EOF);
  printf("\n");
  printf("printf(%%d, EOF): ");
  printf("%d", EOF);
  printf("\n");
  printf("printf(%%c, c): ");
  char c = EOF;
  printf("%c", c);
  printf("\n");
}

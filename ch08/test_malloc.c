#include <stdio.h>
#include <string.h>

main() {
  void *malloc(unsigned);
  char *s;

  s = malloc(10);
  /* this works because malloc reserves NALLOC (1024) contiguous bytes */
  strcpy(s, "foobarbazbaq");
  printf("%s\n", s);
}

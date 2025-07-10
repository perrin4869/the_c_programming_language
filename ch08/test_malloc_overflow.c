#include <stdio.h>
#include <string.h>

main() {
  void *malloc(unsigned);
  char *s;

  if ((s = malloc(10241)) == NULL)
    return 1;
  /* this works because malloc reserves NALLOC (1024) contiguous bytes */
  strcpy(s, "foobarbazbaq");
  printf("%s\n", s);
}

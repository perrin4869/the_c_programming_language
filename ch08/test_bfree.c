#include <stdio.h>
#include <string.h>

#include "header.h"

#define SIZE 100

main() {
  void *malloc(unsigned);
  void *bfree(void *, unsigned);
  char s[SIZE], *m;

  malloc(1); /* make sure base and freep are initialized */
  bfree((void *)s, SIZE);
  if ((m = (char *)malloc(32)) == NULL)
    return 1;

  strcpy(m, "foobarbazbaq");
  /* let's see if the original memory got assigned! */
  printf("m: %s\n", m);
  printf("s->s.size: %u\n", ((Header *)s)->s.size);
  printf("s: %s\n", s + sizeof(Header) * 4);
}

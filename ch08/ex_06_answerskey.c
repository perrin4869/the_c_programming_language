#include "syscalls.h"
#include <stddef.h>

/* note to self: malloc was not defined in the answers key */
void *malloc(unsigned);

/* calloc: allocate n objects of size size */
void *calloc(unsigned n, unsigned size) {
  unsigned i, nb;
  char *p, *q;

  nb = n * size;
  if ((p = q = malloc(nb)) != NULL)
    for (i = 0; i < nb; i++)
      *p++ = 0;
  return q;
}

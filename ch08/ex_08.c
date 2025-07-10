#include "header.h"

void free(void *p);

void bfree(void *p, unsigned n) {
  unsigned s;
  Header *bp;

  /* might not allocate 100% of the bytes */
  /* allows for zero bytes too if it's only a header */
  s = n / sizeof(Header);
  if (n < 1)
    return;
  bp = (Header *)p;
  bp->s.size = s;
  free((void *)(bp + 1));
}

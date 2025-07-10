#include "header.h"
#include "syscalls.h"

void free(void *p);

/* free: free an arbitrary block p of n chars */
unsigned bfree(void *p, unsigned n) {
  Header *hp;

  if (n < sizeof(Header))
    return 0; /* too small to be useful */
  hp = (Header *)p;
  hp->s.size = n / sizeof(Header);
  free((void *)(hp + 1));
  return hp->s.size;
}

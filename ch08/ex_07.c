#include <stddef.h>

#include "header.h"

static Header base;          /* empty list to get started */
static Header *freep = NULL; /* start of free list */

static Header *morecore(unsigned nu);

#define MAXALLOC 10 * 1024 /* maximum 10kB */

/* malloc: general-purpose storage allocator */
void *malloc(unsigned nbytes) {
  Header *p, *prevp;
  Header *morecore(unsigned);
  unsigned nunits;

  if (nbytes >= MAXALLOC)
    return NULL;

  /*
   * note to self: the -1 is there to implement the rounding operation
   * let's say, sizeof(Header) = 8 and nbytes = 8, then we need 2 units
   * if we remove the -1, the calculation gives us 3 units
   * generally, `(n - 1)/m + 1` calculates the ceil of n/m when n and m
   * are positive integers
   * `(n - 1)/m + 1` is equivalent to `ceil(n / (double)m)`
   * */
  nunits = (nbytes + sizeof(Header) - 1) / sizeof(Header) + 1;
  if ((prevp = freep) == NULL) { /* no free list yet */
    base.s.ptr = freep = prevp = &base;
    base.s.size = 0;
  }
  for (p = prevp->s.ptr;; prevp = p, p = p->s.ptr) {
    if (p->s.size >= nunits) { /* big enough */
      if (p->s.size == nunits) /* exactly */
        prevp->s.ptr = p->s.ptr;
      else {
        p->s.size -= nunits;
        p += p->s.size;
        p->s.size = nunits;
      }
      freep = prevp;
      return (void *)(p + 1);
    }
    if (p == freep) /* wrapped around free list */
      if ((p = morecore(nunits)) == NULL)
        return NULL; /* none left */
  }
}

#define NALLOC 1024 /* minimum #units to request */
/* morecore: ask system for more memory */
static Header *morecore(unsigned nu) {
  char *cp, *sbrk(int);
  Header *up;
  void free(void *ap);

  if (nu < NALLOC)
    nu = NALLOC;
  cp = sbrk(nu * sizeof(Header));
  if (cp == (char *)-1) /* no space at all */
    return NULL;
  up = (Header *)cp;
  up->s.size = nu;
  free((void *)(up + 1));
  return freep;
}

/* free: put block ap in free list */
void free(void *ap) {
  Header *bp, *p;

  bp = (Header *)ap - 1; /* point to block header */

  if (bp->s.size >= MAXALLOC)
    return;

  for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
    if (p >= p->s.ptr && (bp > p || bp < p->s.ptr))
      break; /* freed block at start or end of arena */

  if (bp + bp->s.size == p->s.ptr) { /* join to upper nbr */
    bp->s.size += p->s.ptr->s.size;
    bp->s.ptr = p->s.ptr->s.ptr;
  } else
    bp->s.ptr = p->s.ptr;
  if (p + p->s.size == bp) { /* join to lower nbr */
    p->s.size += bp->s.size;
    p->s.ptr = bp->s.ptr;
  } else
    p->s.ptr = bp;
  freep = p;
}

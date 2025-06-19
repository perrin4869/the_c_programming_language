#include "nlist.h"
#include <stdio.h>

struct nlist *lookup(char *);
struct nlist *install(char *, char *);
void undef(char *);

main() {
  install("foo", "bar");
  printf("foo: %p %s\n", lookup("foo"), lookup("foo")->defn);
  undef("bar"); /* should run without crashing */
  undef("foo");
  printf("foo: %p\n", lookup("foo"));
}

#include <stdio.h>

#define swap(t, x, y)                                                          \
  {                                                                            \
    t tmp;                                                                     \
    tmp = x;                                                                   \
    x = y;                                                                     \
    y = tmp;                                                                   \
  }

main() {
  int foo = 3, bar = 5;
  swap(int, foo, bar);

  printf("foo: %d, bar: %d\n", foo, bar);
}

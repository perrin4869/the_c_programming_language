#include <stdio.h>

#define swap(t, x, y)                                                          \
  t _tmp;                                                                      \
  _tmp = x;                                                                    \
  x = y;                                                                       \
  y = _tmp;

main() {
  int foo = 1, bar = 2;
  swap(int, foo, bar);
  printf("foo: %d, bar: %d\n", foo, bar);
}

#include <stdio.h>

void print_double_prototyped(double);

main() {
  print_double(2);
  print_double(2.0);

  print_double_prototyped(2);
  print_double_prototyped(2.0);

  printf("%u %d\n", ~0U >> 1, (int)(~0U >> 1));
}

void print_double(double d) { printf("%lf\n", d); }
void print_double_prototyped(double d) { printf("%lf\n", d); }

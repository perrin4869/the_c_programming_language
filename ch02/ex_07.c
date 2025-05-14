#include <stdio.h>

int invert(unsigned x, int p, int n);

main() {}

int invert(unsigned x, int p, int n) { return x ^ (~(~0 << n) << (p + 1 - n)); }

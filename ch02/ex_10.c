#include <stdio.h>

int lower(int c);

main() {
  printf("%c", lower('A'));
  printf("%c", lower('a'));
  printf("%c", lower('Z'));
}

int lower(int c) { return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c; }

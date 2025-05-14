#include <ctype.h>
#include <stdio.h>

int htoi(const char s[]);

main() {
  printf("c = %d\n", htoi("c"));
  printf("e = %d\n", htoi("e"));
  printf("0xe = %d\n", htoi("0xe"));
  printf("0Xe = %d\n", htoi("0Xe"));

  printf("0XE = %d\n", htoi("0XE"));
  printf("0X3 = %d\n", htoi("0X3"));
  printf("0x13 = %d\n", htoi("0x13"));
  printf("0xac = %d\n", htoi("0xac"));
  printf("0x1a = %d\n", htoi("0x1a"));
  printf("0x1aa = %d\n", htoi("0x1aa"));
}

int htoi(const char s[]) {
  int i = 0;
  int num = 0;

  if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
    i = 2;
  }

  while (s[i] != '\0') {
    if (isdigit(s[i])) {
      num = num * 16 + s[i] - '0';
    } else {
      num = num * 16 + tolower(s[i]) - 'a' + 10;
    }
    i++;
  }

  return num;
}

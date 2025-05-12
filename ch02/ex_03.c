#include <ctype.h>
#include <stdio.h>

int htoi(const char s[]);

main() {
  printf("%d\n", htoi("F"));
  printf("%d\n", htoi("0xFF"));
  printf("%d\n", htoi("a"));
  printf("%d\n", htoi("0Xab"));
}

int htoi(const char s[]) {
  int i = 0, d;
  int sum = 0;

  if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
    i = 2;
  }

  for (; s[i] != '\0'; i++) {
    if (isdigit(s[i])) {
      d = s[i] - '0';
    } else if (s[i] >= 'A' && s[i] <= 'F') {
      d = 10 + s[i] - 'A';
    } else if (s[i] >= 'a' && s[i] <= 'f') {
      d = 10 + s[i] - 'a';
    } else {
      printf("Invalid input");
      exit(1);
    }
    sum = sum * 0x10 + d;
  }

  return sum;
}

#include <stdio.h>
#include <string.h>

void reverse(char s[]);

main() {
  char s[] = "foo";
  reverse(s);
  printf("%s\n", s);
  reverse(s);
  printf("%s\n", s);
}

void reverse(char s[]) {
  static int i = 0;
  static int j = 0;
  char tmp;

  if (s[i] == '\0') {
    j = 0;
  } else {
    i++;
    reverse(s);
    i--;

    if (j < i) {
      tmp = s[i];
      s[i] = s[j];
      s[j] = tmp;
    }

    j++;
  }
}

/*
 * copied over from my first runthrough:
 */

void reverser(char s[], int i, int len);

/*
 * this one kinda sucks because it traverses the string 1.5*strlen(s) times
 * my solution only traverses it strlen(s) times
 */
void reverse_answerskey(char s[]) {
  int len = strlen(s);
  reverser(s, 0, len);
}

void reverser(char s[], int i, int len) {
  int j, tmp;

  j = len - i - 1;
  if (i < j) {
    tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
    reverser(s, i + 1, len);
  }
}

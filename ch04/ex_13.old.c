#include <stdio.h>
#include <string.h>

#define MAX 100

void reverse(char[]);
void reverse_answerskey(char[]);

main() {
  char buf[MAX] = "omg";
  reverse(buf);
  printf("%s\n", buf);

  char buf2[MAX] = "omg1";
  reverse(buf2);
  printf("%s\n", buf2);

  char buf3[MAX] = "omg";
  reverse(buf3);
  printf("%s\n", buf3);

  char buf4[MAX] = "omg1";
  reverse(buf4);
  printf("%s\n", buf4);
}

void reverse(char s[]) {
  static int i, j;
  char tmp;

  if (s[i] != '\0') {
    i++;
    reverse(s);

    i--;
    if (j < i) {
      tmp = s[j];
      s[j] = s[i];
      s[i] = tmp;

      j++;
    }
  } else
    j = 0;
}

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

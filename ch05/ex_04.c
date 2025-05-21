#include <stdio.h>
#include <string.h>

int strend(char *s, char *t);
int strend_answerskey(char *s, char *t);

main() {
  printf("strend(\"foobar\", \"bar\"): %d\n", strend("foobar", "bar"));
  printf("strend(\"foo\", \"bar\"): %d\n", strend("foo", "bar"));
  printf("strend(\"foo\", \"barfoo\"): %d\n", strend("foo", "barfoo"));

  printf("answerskey:\n");
  printf("strend(\"foobar\", \"bar\"): %d\n",
         strend_answerskey("foobar", "bar"));
  printf("strend(\"foo\", \"bar\"): %d\n", strend_answerskey("foo", "bar"));
  printf("strend(\"foo\", \"barfoo\"): %d\n",
         strend_answerskey("foo", "barfoo"));
}

int strend(char *s, char *t) {
  int ls, lt;

  ls = strlen(s);
  lt = strlen(t);
  if (lt > ls)
    return 0;
  s += ls - 1;
  t += lt - 1;

  while (*s-- == *t-- && --lt)
    ;
  return lt == 0;
}

int strend_old(const char *s, const char *t) {
  int ls = strlen(s);
  int lt = strlen(t);

  if (lt > ls)
    return 0;
  s += ls - lt;
  while (*s == *t && *s != '\0') {
    s++;
    t++;
  }
  return *s == '\0';
}

/* strend: return 1 if string t occurs at the end of s */
int strend_answerskey(char *s, char *t) {
  char *bs = s; /* remembering the beginning of the strs */
  char *bt = t;

  for (; *s; s++) /* at the end of the string s */
    ;
  for (; *t; t++) /* at the end of the string t */
    ;
  for (; *s == *t; s--, t--)
    if (bs == s || bt == t)
      break; /* at the beginning of a str */

  if (*s == *t && bt == t && *s != '\0')
    return 1;
  else
    return 0;
}

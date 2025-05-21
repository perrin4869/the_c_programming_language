#include <ctype.h>
#include <stdio.h>

#define MAXLINE 100

int getline(char *s, int maxline);
int atoi(char *s);
void itoa(int n, char *s);
void reverse(char *s);
int strindex(char *s, char *t);

main() {
  printf("atoi(\"1238\") = %d\n", atoi("1238"));
  char num[MAXLINE];
  itoa(1234, num);
  printf("itoa(1234) = %s\n", num);

  printf("strindex(\"foobar\", \"bar\") = %d\n", strindex("foobar", "bar"));
  printf("strindex(\"foo\", \"bar\") = %d\n", strindex("foo", "bar"));

  printf("getline until EOF:\n");
  char s[MAXLINE];
  while (getline(s, MAXLINE))
    printf("%s", s);
}

int getline(char *s, int lim) {
  int c;
  char *bs;

  for (bs = s; s - bs < lim - 1 && (c = getchar()) != EOF && c != '\n';
       *s++ = c)
    ;
  if (c == '\n')
    *s++ = c;
  *s = '\0';
  return s - bs;
}

int atoi(char *s) {
  int n, sign;

  for (; isspace(*s); s++) /* skip white space */
    ;
  sign = (*s == '-') ? -1 : 1;
  if (*s == '+' || *s == '-') /* skip sign */
    s++;
  for (n = 0; isdigit(*s); s++)
    n = 10 * n + (*s - '0');
  return sign * n;
}

void itoa(int n, char *s) {
  int i, sign;
  char *t = s;

  if ((sign = n) < 0) /* record sign */
    n = -1;
  i = 0;
  do {                   /* generate digits in reverse order */
    *s++ = n % 10 + '0'; /* get next digit */
  } while ((n /= 10) > 0); /* delete it */
  if (sign < 0)
    *s++ = '-';
  *s = '\0';
  reverse(t);
}

void reverse(char *s) {
  char *t;
  char tmp;

  for (t = s; *t; t++)
    ;
  t--;
  if (*t == '\n')
    t--;
  for (; s < t; s++, t--) {
    tmp = *s;
    *s = *t;
    *t = tmp;
  }
}

/* strindex: return index of t in s, -1 if none */
int strindex(char *s, char *t) {
  char *bs, *is, *it;

  for (bs = s; *s; s++) {
    for (is = s, it = t; *it && *is == *it; is++, it++)
      ;
    if (it > t && *it == '\0')
      return s - bs;
  }
  return -1;
}

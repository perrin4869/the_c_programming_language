#include <stdio.h>

void strncpy_sol(char *s, char *t, int n);
void strncat_sol(char *s, char *t, int n);
int strncmp_sol(char *s, char *t, int n);

main() {
  char s1[10] = "foobar";
  strncpy_sol(s1, "barbaz", 3);
  printf("strncpy(\"foobar\", \"barbaz\", 3) = %s\n", s1);

  char s2[10] = "foo";
  strncat_sol(s2, "barbaz", 3);
  printf("strncat(\"foo\", \"barbaz\", 3) = %s\n", s2);
  printf("strncmp(\"foobar\", \"foo\", 3) = %d\n",
         strncmp_sol("foobar", "foo", 3));
  printf("strncmp(\"foobar\", \"foobaz\", 3) = %d\n",
         strncmp_sol("foobar", "foobaz", 6));
}

void strncpy_sol(char *s, char *t, int n) {
  while (n-- && *t)
    *s++ = *t++;
  /* should pad with \0 if t ends too early for the remainder of n */
}

void strncat_sol(char *s, char *t, int n) {
  while (*s)
    s++;
  while (n-- && *t)
    *s++ = *t++;
  *s = '\0';
}

int strncmp_sol(char *s, char *t, int n) {
  while (--n && *s && *s == *t) {
    s++;
    t++;
  }

  return *s - *t;
}

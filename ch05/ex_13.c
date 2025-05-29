#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10
#define MAXLINE 100
#define MAXLINES 10000

int getline(char line[], int maxline);
char *alloc(int n);
int push(char *lines[], char line[], int n);

main(int argc, char *argv[]) {
  int i, n, cur;
  char line[MAXLINE];
  char *lines[MAXLINES];

  n = N;
  if (argc > 1 && *argv[1] == '-') {
    n = atoi(argv[1] + 1);
    if (n <= 0) {
      printf("n is a positive integer\n");
      return -1;
    }
  }

  while (getline(line, MAXLINE) > 0 && (cur = push(lines, line, n)) > 0)
    ;

  if (cur < 0) {
    printf("mem alloc fail");
    return -1;
  }

  for (i = 0; i < cur; i++)
    printf("%s\n", lines[i]);

  return 0;
};

int push(char *lines[], char line[], int n) {
  static int i = 0;
  int j;
  int len;
  char *l;

  len = strlen(line);
  if ((l = alloc(len)) == NULL)
    return -1;
  line[len - 1] = '\0'; /* remove newline */
  strcpy(l, line);

  if (i < n)
    lines[i++] = l;
  else {
    for (j = 0; j < n - 1; j++)
      lines[j] = lines[j + 1];
    lines[j] = l;
  }

  return i;
}

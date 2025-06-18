#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tnode.h"

#define COUNT 6
#define MAXWORD 100

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);

/* word frequency count */
main(int argc, char *argv[]) {
  struct tnode *root;
  char word[MAXWORD];
  int c = 0;

  if (argc > 1)
    c = atoi(argv[1]);
  if (c < 1)
    c = COUNT;

  root = NULL;
  while (getword(word, MAXWORD) != EOF)
    if (isalpha(word[0])) {
      if (strlen(word) > c)
        word[c] = '\0';
      root = addtree(root, word);
    }
  treeprint(root);
  return 0;
}

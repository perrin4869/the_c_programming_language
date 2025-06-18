#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "tnode.h"

#define MAXWORD 100
struct tnode *addtree(struct tnode *, char *);
struct tnode *freqsort(struct tnode *, struct tnode *);
void treeprint(struct tnode *);
int getword(char *, int);

/* word frequency count */
main() {
  struct tnode *root, *sorted;
  char word[MAXWORD];

  root = NULL;
  while (getword(word, MAXWORD) != EOF)
    if (isalpha(word[0]))
      root = addtree(root, word);
  sorted = NULL;
  sorted = freqsort(root, sorted);
  treeprint(sorted);
  return 0;
}

struct tnode *addtreex(struct tnode *, struct tnode *);

/* freqsort: sort tree p by frequency */
struct tnode *freqsort(struct tnode *p, struct tnode *f) {
  if (p != NULL) {
    f = addtreex(f, p);
    freqsort(p->left, f);
    freqsort(p->right, f);
  }
  return f;
}

/* addtreex: add a node p into a binary tree f */
struct tnode *addtreex(struct tnode *f, struct tnode *p) {
  struct tnode *talloc(void);
  int cond;

  if (f == NULL) { /* a new word has arrived */
    f = talloc();  /* make a new node */
    f->word = p->word;
    f->count = p->count;
    f->left = f->right = NULL;
  } else if ((cond = (f->count - p->count)) <= 0)
    f->left = addtreex(f->left, p);
  else
    f->right = addtreex(f->right, p);
  return f;
}

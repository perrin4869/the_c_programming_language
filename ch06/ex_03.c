#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lnode {
  struct lnode *next;
  int l;
};

struct tnode {         /* the tree node: */
  char *word;          /* points to the text */
  struct lnode lines;  /* list of lines */
  struct lnode *cur;   /* avoid having to traverse the list to add a line */
  struct tnode *left;  /* left child */
  struct tnode *right; /* right child */
};

#define MAXWORD 100

struct tnode *addtreex(struct tnode *, char *, int);
void treexprint(struct tnode *);
int getword(char *, int, int *);

main() {
  struct tnode *root;
  char word[MAXWORD];
  int l;

  root = NULL;
  l = 1;
  while (getword(word, MAXWORD, &l) != EOF) {
    if (isalpha(word[0]))
      root = addtreex(root, word, l);
  }
  treexprint(root);
  return 0;
}

struct tnode *talloc(void);

/* addtreex: add a node with w, at or below p */
struct tnode *addtreex(struct tnode *p, char *w, int l) {
  char *strdup(char *);
  int cond;

  if (p == NULL) { /* a new word has arrived */
    p = talloc();  /* make a new node */
    p->word = strdup(w);
    p->lines.l = l;
    p->lines.next = NULL;
    p->cur = &p->lines;
    p->left = p->right = NULL;
  } else if ((cond = strcmp(w, p->word)) < 0)
    p->left = addtreex(p->left, w, l);   /* repeated word */
  else if (cond > 0)                     /* less than into left subtree */
    p->right = addtreex(p->right, w, l); /* repeated word */
  else {
    p->cur->next = (struct lnode *)malloc(sizeof(struct lnode));
    p->cur = p->cur->next;
    p->cur->l = l;
    p->cur->next = NULL;
  }
  return p;
}

/* treexprint: in-order print of tree p if p->match == YES */
void treexprint(struct tnode *p) {
  struct lnode *l;
  if (p != NULL) {
    treexprint(p->left);
    printf("%s:", p->word);
    for (l = &p->lines; l != NULL; l = l->next)
      printf(" %d", l->l);
    printf("\n");
    treexprint(p->right);
  }
}

/* getword: get next word or character from input */
int getword(char *word, int lim, int *l) {
  int c, getch(void);
  void ungetch(int);
  char *w = word;

  while (isspace(c = getch()))
    if (c == '\n')
      (*l)++;
  if (c != EOF)
    *w++ = c;
  if (!isalpha(c)) {
    *w = '\0';
    return c;
  }
  for (; --lim > 0; w++)
    if (!isalnum(*w = getch())) {
      ungetch(*w);
      break;
    }
  *w = '\0';
  return word[0];
}

/* talloc: make a tnode */
struct tnode *talloc(void) {
  return (struct tnode *)malloc(sizeof(struct tnode));
}

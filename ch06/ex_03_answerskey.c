#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 100

struct linklist { /* linked list of line numbers */
  int lnum;
  struct linklist *ptr;
};

struct tnode {            /* the tree node: */
  char *word;             /* points to the text */
  struct linklist *lines; /* line numbers */
  struct tnode *left;     /* left child */
  struct tnode *right;    /* right child */
};

struct tnode *addtreex(struct tnode *, char *, int);
int getword(char *, int);
int noiseword(char *);
void treexprint(struct tnode *);

/* cross-references */
main() {
  struct tnode *root;
  char word[MAXWORD];
  int linenum = 1;

  root = NULL;
  while (getword(word, MAXWORD) != EOF)
    if (isalpha(word[0]) && noiseword(word) == -1)
      root = addtreex(root, word, linenum);
    else if (word[0] == '\n')
      linenum++;
  treexprint(root);
  return 0;
}

struct tnode *talloc(void);
struct linklist *lalloc(void);
void addln(struct tnode *, int);

/* addtreex: add a node with w, at or below p */
struct tnode *addtreex(struct tnode *p, char *w, int linenum) {
  char *strdup(char *);
  int cond;

  if (p == NULL) { /* a new word has arrived */
    p = talloc();  /* make a new word */
    p->word = strdup(w);
    p->lines = lalloc();
    p->lines->lnum = linenum;
    p->lines->ptr = NULL;
    p->left = p->right = NULL;
  } else if ((cond = strcmp(w, p->word)) == 0)
    addln(p, linenum);
  else if (cond < 0)
    p->left = addtreex(p->left, w, linenum);
  else if (cond > 0)
    p->right = addtreex(p->right, w, linenum);
  return p;
}

/* addln: add a line number to the linked list */
void addln(struct tnode *p, int linenum) {
  struct linklist *temp;

  temp = p->lines;
  while (temp->ptr != NULL && temp->lnum != linenum)
    temp = temp->ptr;
  if (temp->lnum != linenum) {
    temp->ptr = lalloc();
    temp->ptr->lnum = linenum;
    temp->ptr->ptr = NULL;
  }
}

/* treexprint: int-order print of tree p */
void treexprint(struct tnode *p) {
  struct linklist *temp;
  if (p != NULL) {
    treexprint(p->left);
    printf("%10s: ", p->word);
    for (temp = p->lines; temp != NULL; temp = temp->ptr)
      printf("%4d ", temp->lnum);
    printf("\n");
    treexprint(p->right);
  }
}

/* lalloc: make a linklist node */
struct linklist *lalloc(void) {
  return (struct linklist *)malloc(sizeof(struct linklist));
}

/* noiseword: identitfy word as a noise word */
int noiseword(char *w) {
  /* clang-format off */
  static char *nw[] = {
    "a",
    "an",
    "and",
    "are",
    "in",
    "is",
    "of",
    "or",
    "that",
    "the",
    "this",
    "to",
  };
  /* clang-format on */
  int cond, mid;
  int low = 0;
  int high = sizeof(nw) / sizeof(char *) - 1;

  while (low <= high) {
    mid = (low + high) / 2;
    if ((cond = strcmp(w, nw[mid])) < 0)
      high = mid - 1;
    else if (cond > 0)
      low = mid + 1;
    else
      return mid;
  }
  return -1;
}

/* talloc: make a tnode */
struct tnode *talloc(void) {
  return (struct tnode *)malloc(sizeof(struct tnode));
}

/* getword: get next word or character from input */
int getword(char *word, int lim) {
  int c, getch(void);
  void ungetch(int);
  char *w = word;

  while (isspace(c = getch()) && c != '\n')
    ;
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

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXWORD 100

struct nlist {        /* table entry: */
  struct nlist *next; /* next entry in the chain */
  char *name;         /* defined name */
  char *defn;         /* replacement text */
};

void error(int, char *);
int getch(void);
void getdef(void);
int getword(char *, int);
struct nlist *install(char *, char *);
struct nlist *lookup(char *);
void skipblanks(void);
void undef(char *);
void ungetch(int);
void ungets(char *);

/* simple version of #define processor */
main() {
  char w[MAXWORD];
  struct nlist *p;
  while (getword(w, MAXWORD) != EOF)
    if (strcmp(w, "#") == 0) /* beginning of a direct. */
      getdef();
    else if (!isalnum(w[0]))
      printf("%s", w); /* cannot be defined */
    else if ((p = lookup(w)) == NULL)
      printf("%s", w); /* not defined */
    else
      ungets(p->defn);
  return 0;
}

void getdef(void) {
  int c, i;
  char def[MAXWORD], dir[MAXWORD], name[MAXWORD];

  skipblanks();
  if (!isalpha(c = getword(dir, MAXWORD)))
    error(dir[0], "getdef: expecting a directive after #");
  else if (strcmp(dir, "define") == 0) {
    skipblanks();
    if (!isalpha(getword(name, MAXWORD)))
      error(name[0], "getdef: non-alpha - name expected");
    else {
      skipblanks();
      for (i = 0; i < MAXWORD - 1; i++)
        if ((def[i] = getch()) == EOF || def[i] == '\n')
          break; /* end of definition */
      def[i] = '\0';
      if (i <= 0) /* no definition? */
        error('\n', "getdef: incomplete define");
      else /* install definition */
        install(name, def);
    }
  } else if (strcmp(dir, "undef") == 0) {
    skipblanks();
    if (!isalpha(getword(name, MAXWORD)))
      error(name[0], "getdef: non-alpha in undef");
    else
      undef(name);
  } else
    error(dir[0], "getdef: expecting a directive after #");
}

/* error: print error message and skip the rest of the line */
void error(int c, char *s) {
  printf("error: %s\n", s);
  while (c != EOF && c != '\n')
    c = getch();
}

/* skipblanks: skip blank and tab characters */
void skipblanks(void) {
  int c;

  while ((c = getch()) == ' ' || c == '\t')
    ;
  ungetch(c);
}

/* slightly modified version of ex01 - in order to handle definitions inside
 * string literals, return spaces and remove comments */
int getword(char *word, int lim) {
  int c, d, comment(void), getch(void);
  void ungetch(int);
  char *w = word;

  c = getch();
  if (c != EOF)
    *w++ = c;
  if (isalpha(c) || c == '_') {
    for (; --lim > 0; w++)
      if (!isalnum(*w = getch()) && *w != '_') {
        ungetch(*w);
        break;
      }
  } else if (c == '\'' || c == '"') {
    for (; --lim > 0; w++)
      if ((*w = getch()) == '\\')
        *++w = getch();
      else if (*w == c) {
        w++;
        break;
      } else if (*w == EOF)
        break;
  } else if (c == '/')
    if ((d = getch()) == '*') {
      c = comment();
      w--; /* modification from the original exercise, return nothing */
    } else
      ungetch(d);
  *w = '\0';
  return c;
}

/* comment: skip over comment and return a character */
int comment(void) {
  int c, getch(void);
  void ungetch(int);

  while ((c = getch()) != EOF)
    if (c == '*')
      if ((c = getch()) == '/')
        break;
      else
        ungetch(c);
  return c;
}

#include <stdio.h>
#include <string.h>

enum { NAME, PARENS, BRACKETS };
enum { NO, YES };

void dcl(void);
void dirdcl(void);
void errmsg(char *);
int gettoken(void);

extern int tokentype;
extern char token[];
extern char name[];
extern char out[];
extern int prevtoken;

/* dcl: parse a declarator */
void dcl(void) {
  int ns;

  for (ns = 0; gettoken() == '*';) /* count *'s */
    ns++;
  dirdcl();
  /* note to self:
   * dereferencing is lower precedence than () and [],
   * so apply it after the dirdcl
   */
  while (ns-- > 0)
    strcat(out, " pointer to");
}

/* dirdcl: parse a direct declarator */
void dirdcl(void) {
  int type;

  if (tokentype == '(') { /* ( dcl ) */
    dcl();
    if (tokentype != ')')
      errmsg("error: missing )\n");
  } else if (tokentype == NAME) /* variable name */
    strcpy(name, token);
  else
    errmsg("error: expected name or (dcl)\n");
  while ((type = gettoken()) == PARENS || type == BRACKETS)
    if (type == PARENS)
      strcat(out, " function returning");
    else {
      strcat(out, " array");
      strcat(out, token);
      strcat(out, " of");
    }
}

/* errmsg: print error message and indicate avail. token */
void errmsg(char *msg) {
  printf("%s", msg);
  prevtoken = YES;
}

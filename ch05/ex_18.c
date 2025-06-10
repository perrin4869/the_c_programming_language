#include <stdio.h>
#include <string.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };

void dcl(void);
void dirdcl(void);

int gettoken(void);
int tokentype;           /* type fo the last token */
char token[MAXTOKEN];    /* last token string */
char name[MAXTOKEN];     /* identifier name */
char datatype[MAXTOKEN]; /* data type = char, int, etc */
char out[1000];          /* output string */

main() /* convert declarotion to words */
{
  while (gettoken() != EOF) { /* 1st token on line */
    strcpy(datatype, token);  /* is the datatype */
    out[0] = '\0';
    dcl(); /* parse rest of line */
    if (tokentype != '\n') {
      printf("syntax error\n");
      /* skip to end of line and reset output */
      while (gettoken() != '\n' && tokentype != EOF)
        ;
      out[0] = '\0';
    } else
      printf("%s: %s %s\n", name, out, datatype);
  }
  return 0;
}

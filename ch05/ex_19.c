#include <stdio.h>
#include <string.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };

int gettoken(void);
int tokentype;        /* type of the last token */
char token[MAXTOKEN]; /* last token string */
char out[1000];       /* output string */

/* undcl: convert word description to declaration */
main() {
  int type;
  char temp[MAXTOKEN];

  while (gettoken() != EOF) {
    strcpy(out, token);
    while ((type = gettoken()) != '\n')
      if (type == PARENS || type == BRACKETS)
        if (out[0] == '*') {
          sprintf(temp, "(%s)%s", out, token);
          strcpy(out, temp);
        } else
          strcat(out, token);
      else if (type == '*') {
        sprintf(temp, "*%s", out);
        strcpy(out, temp);
      } else if (type == NAME) {
        sprintf(temp, "%s %s", token, out);
        strcpy(out, temp);
      } else
        printf("invalid input at %s\n", token);
    printf("%s\n", out);
  }

  return 0;
}

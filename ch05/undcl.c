#include <stdio.h>
#include <string.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };

int gettoken(void);
int tokentype;        /* type fo the last token */
char token[MAXTOKEN]; /* last token string */
char out[1000];       /* output string */

main() {
  int type;
  char temp[MAXTOKEN];

  while (gettoken() != EOF) {
    strcpy(out, token);
    while ((type = gettoken()) != '\n')
      if (type == PARENS || type == BRACKETS)
        strcat(out, token);
      else if (type == '*') {
        sprintf(temp, "(*%s)", out);
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

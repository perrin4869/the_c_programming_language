#include "polish_calculator.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h> /* for atof() */

#define MAXOP 100 /* max size of operand or operator */
#define VARS 26
#define VARIABLE 'v'

int getop(char[]);
void push(double);
double pop(void);

main() {
  int type;
  double op2;
  char s[MAXOP];
  double vars[VARS] = {0.0};
  int lastvar;

  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case VARIABLE:
      lastvar = s[0] - 'a';
      push(vars[lastvar]);
      break;
    case '=':
      pop();
      vars[lastvar] = pop();
      push(vars[lastvar]);
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0)
        push(pop() / op2);
      else
        printf("error: zero divisor\n");
      break;
    case '\n':
      printf("\t%.8g\n", op2 = pop());
      vars['p' - 'a'] = op2;
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }
  return 0;
}

/* getop: get next operator or numeric operand */
int getop(char s[]) {
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;

  s[1] = '\0';

  if (islower(c))
    return VARIABLE;

  if (!isdigit(c) && c != '.')
    return c;
  i = 0;
  if (isdigit(c))
    while (isdigit(s[++i] = c = getch()))
      ;

  if (c == '.')
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if (c != EOF)
    ungetch(c);
  return NUMBER;
}

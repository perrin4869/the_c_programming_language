#include "polish_calculator.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <string.h>

#define MAXOP 100 /* max size of operand or operator */
#define FUNC '1'

int getop(char[]);
void push(double);
double pop(void);

main() {
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case FUNC:
      if (!strcmp(s, "sin"))
        push(sin(pop()));
      else if (!strcmp(s, "exp"))
        push(exp(pop()));
      else if (!strcmp(s, "pow")) {
        op2 = pop();
        push(pow(op2, pop()));
      } else
        printf("error: unknown function\n");
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
      printf("\t%.8g\n", pop());
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

  i = 0;
  if (isalpha(c)) {
    while (isalpha((s[++i] = c = getch())))
      ;
    ungetch(c);
    s[i] = '\0';
    return FUNC;
  }

  if (!isdigit(c) && c != '.')
    return c;
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

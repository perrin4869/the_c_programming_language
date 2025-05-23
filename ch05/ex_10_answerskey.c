#include "../ch04/polish_calculator.h"
#include <stdio.h>
#include <stdlib.h> /* for atof() */

#define MAXOP 100 /* max size of operand or operator */

int getop(char[]);
void push(double);
void ungets(char *s);
double pop(void);

main(int argc, char *argv[]) {
  double op2;
  char s[MAXOP];

  while (--argc > 0) {
    /* getop gets one extra character, so make sure it's not stuck */
    ungets(" ");
    ungets(*++argv);
    switch (getop(s)) {
    case NUMBER:
      push(atof(s));
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
      argc = 1;
      break;
    }
  }
  printf("\t%.8g\n", pop());
  return 0;
}

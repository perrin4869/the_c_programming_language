#include "polish_calculator.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h> /* for atof() */

#define MAXOP 100 /* max size of operand or operator */

int getop(char[]);
void push(double);
double pop(void);
void clear(void);

/* the scope of this solution is pretty narrow */
main() {
  int type;
  double op2;
  char s[MAXOP];
  char vars['z' - 'a' + 1] = {0};
  int lastvar = 0;
  double last = 0.0;

  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case '=':
      /*
       * this is the variable value, assume it comes right before the '='
       * operation as per the answerskey
       */
      pop();
      vars[lastvar] = pop();
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
      printf("\t%.8g\n", last = pop());
      break;
    default:
      if (islower(s[0])) {
        lastvar = s[0] - 'a';
        push(vars[lastvar]);
      } else if (s[0] == 'V') {
        push(last);
      } else
        printf("error: unknown command %s\n", s);
      break;
    }
  }
  return 0;
}

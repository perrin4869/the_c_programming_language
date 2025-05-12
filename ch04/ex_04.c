#include "polish_calculator.h"
#include <ctype.h>
#include <math.h> /* for fmod() */
#include <stdio.h>
#include <stdlib.h> /* for atof() */

#define MAXOP 100 /* max size of operand or operator */

#define PRINT 'p'
#define DUPLICATE 'd'
#define SWAP 's'
#define CLEAR 'c'

int getop(char[]);
void push(double);
double pop(void);
void clear(void);

main() {
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
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
    case PRINT:
      op2 = pop();
      printf("top element: %g\n", op2);
      push(op2);
      break;
    case DUPLICATE:
      op2 = pop();
      push(op2);
      push(op2);
      break;
    case SWAP: {
      double tmp;
      op2 = pop();
      tmp = pop();
      push(op2);
      push(tmp);
      break;
    }
    case CLEAR:
      clear();
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }
  return 0;
}

#define MAXVAL 100  /* maximum depth of val stack */
int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f) {
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void) {
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

void clear(void) { sp = 0; }

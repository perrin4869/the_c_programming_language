#include <ctype.h>
#include <stdio.h>
#include <stdlib.h> /* for atof() */

void push(double);
double pop(void);

main(int argc, char *argv[]) {
  int type;
  double op2;

  while (--argc) {
    switch (type = **++argv) {
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
      push(atof(*argv));
      /* printf("error: unknown command %s\n", s); */
      break;
    }
  }
  printf("\t%.8g\n", pop());
  return 0;
}

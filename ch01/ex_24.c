#include <stdio.h>

void parse(int c);
int is_open_parenthesis(int c);
int is_close_parenthesis(int c);
int close_parenthesis(int c);
void parse_parenthesis(int c);
void parse_literal(int c);
void parse_comment();

main() {
  int c;

  while ((c = getchar()) != EOF) {
    parse(c);
  }
}

void parse(int c) {
  if (is_open_parenthesis(c))
    parse_parenthesis(c);
  else if (is_close_parenthesis(c))
    printf("A close parenthes %c is closing despite no matching opening "
           "parenthesis\n",
           c);
  else if (c == '"' || c == '\'')
    parse_literal(c);
  else if (c == '/') {
    while ((c = getchar()) == '/')
      ;
    if (c == '*')
      parse_comment();
  }
}

int is_open_parenthesis(int c) { return c == '(' || c == '[' || c == '{'; }
int is_close_parenthesis(int c) { return c == ')' || c == ']' || c == '}'; }

int close_parenthesis(int c) {
  if (c == '{')
    return '}';
  else if (c == '[')
    return ']';
  else if (c == '(')
    return ')';

  return 0;
}

void parse_parenthesis(int c) {
  int d;

  while ((d = getchar()) != close_parenthesis(c) && d != EOF)
    if (d == '"' || d == '\'')
      parse_literal(d);
    else if (is_open_parenthesis(d))
      parse_parenthesis(d);
    else if (is_close_parenthesis(d))
      printf("A close parenthes %c is closing despite no matching opening "
             "parenthesis\n",
             d);
    else if (d == '/') {
      while ((d = getchar()) == '/')
        ;
      if (d == '*')
        parse_comment();
    }

  if (d == EOF)
    printf("A parenthesis %c was not closed\n", c);
}

void parse_literal(int c) {
  int d;

  while ((d = getchar()) != c && d != '\n' && d != EOF)
    if (d == '\\')
      getchar();

  if (d == '\n')
    printf("Newline is not allowed in a literal\n");
  if (d == EOF)
    printf("A literal %c was not closed\n", c);
}

void parse_comment() {
  int c;

  while ((c = getchar()) != EOF)
    if (c == '*') {
      while ((c = getchar()) == '*')
        ;
      if (c == '/')
        return;
    }

  printf("The comment was not closed\n");
}

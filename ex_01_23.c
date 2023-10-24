#include <stdio.h>

void skip_to_end_of_line();
void skip_to_end_of_comment();
void skip_to_end_of_string_literal_and_print();

main() {
  int c;
  int quote;
  int escaping = 0;

  while ((c = getchar()) != EOF) {
    if (c == '/') {
      c = getchar();
      if (c == '/') {
        skip_to_end_of_line();
        putchar('\n');
      } else if (c == '*') {
        skip_to_end_of_comment();
      } else {
        printf("/%c\n", c);
      }
    } else if (c == '"' || c == '\'') {
      quote = c;
      putchar(quote);
      while ((((c = getchar()) != quote && !escaping) || escaping) &&
             c != EOF) {
        if (c == '\\' && !escaping) {
          escaping = 1;
        } else if (escaping) {
          escaping = 0;
        }
        putchar(c);
      }
      putchar(quote);
    } else {
      putchar(c);
    }
  }
}

void skip_to_end_of_line() {
  int c;
  while ((c = getchar()) != '\n')
    ;
}

void skip_to_end_of_comment() {
  int c, d;
  c = getchar();
  d = getchar();
  while ((c != '*' || d != '/') && d != EOF) {
    c = d;
    d = getchar();
  }
}

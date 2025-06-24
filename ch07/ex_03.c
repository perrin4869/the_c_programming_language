#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>

#define MAX_FORMAT 100

void minprintf(char *fmt, ...);

main() {
  minprintf("integer: %10.3d\n", 10);
  minprintf("integer: %10.3ld\n", 10l);
  minprintf("octal: %o\n", 10);
  minprintf("hex: %x\n", 10);
  minprintf("hex (upper): %X\n", 10);
  minprintf("floating point: %f\n", 3.3);
  minprintf("string: %s\n", "omg");
}

/* minprintf: minimal printf with variable argument list */
void minprintf(char *fmt, ...) {
  va_list ap; /* points to each unnamed arg in turn */
  char *p, *sval;
  int ival;
  double dval;
  char format[MAX_FORMAT];
  int i;

  va_start(ap, fmt); /* make ap point to 1st unnamed arg */
  for (p = fmt; *p; p++) {
    if (*p != '%') {
      putchar(*p);
      continue;
    }

    i = 0;
    do
      format[i++] = *p;
    while (!isalpha(*++p));
    if (*p == 'l' || *p == 'h')
      format[i++] = *p++;
    format[i++] = *p;
    format[i] = '\0';

    switch (*p) {
    case 'd':
    case 'o':
    case 'x':
    case 'X':
      ival = va_arg(ap, int);
      printf(format, ival);
      break;
    case 'f':
      dval = va_arg(ap, double);
      printf(format, dval);
      break;
    case 's':
      sval = va_arg(ap, char *);
      printf(format, sval);
      break;
    }
  }
  va_end(ap); /* clean up when done */
}

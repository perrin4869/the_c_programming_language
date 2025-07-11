#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>

#define LOCALFMT 100

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
  char localfmt[LOCALFMT];
  int i, ival;
  unsigned uval;
  double dval;

  va_start(ap, fmt); /* make ap point to 1st unnamed arg */
  for (p = fmt; *p; p++) {
    if (*p != '%') {
      putchar(*p);
      continue;
    }
    i = 0;
    localfmt[i++] = '%'; /* start local fmt */
    while (*(p + 1) && !isalpha(*(p + 1)))
      localfmt[i++] = *++p;   /* collect chars */
    localfmt[i++] = *(p + 1); /* format letter */
    localfmt[i] = '\0';
    switch (*++p) { /* format letter */
    case 'd':
    case 'i':
      ival = va_arg(ap, int);
      printf(localfmt, ival);
      break;
    case 'x':
    case 'X':
    case 'u':
    case 'o':
      uval = va_arg(ap, unsigned);
      printf(localfmt, uval);
      break;
    case 'f':
      dval = va_arg(ap, double);
      printf(localfmt, dval);
      break;
    case 's':
      sval = va_arg(ap, char *);
      printf(localfmt, sval);
      break;
    default:
      printf(localfmt);
      break;
    }
  }
  va_end(ap); /* clean up when done */
}

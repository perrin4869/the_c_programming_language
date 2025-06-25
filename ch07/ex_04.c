#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>

void minscanf(char *fmt, ...);

main() {
  int n;
  float f;
  char s[100];

  scanf("%d", &n);
  printf("%d\n", n);

  minscanf("%d", &n);
  printf("%d\n", n);

  minscanf("%f", &f);
  printf("%f\n", f);

  minscanf("%s", s);
  printf("%s\n", s);
}

void minscanf(char *fmt, ...) {
  va_list ap;
  int *iv, c;
  float *fv;
  char *sv;

  va_start(ap, fmt);
  do {
    while (isspace(*fmt))
      fmt++;
    if (*fmt != '%' || *(fmt + 1) == '%') {
      if (*fmt == '%') /* the case where fmt has %% */
        fmt++;
      while (isspace(c = getchar()))
        ;
      if (c != *fmt) /* next non-space character needs to match the format */
        return;
      continue;
    }

    switch (*++fmt) {
    case 'd':
      iv = va_arg(ap, int *);
      scanf("%d", iv);
      break;
    case 'f':
      fv = va_arg(ap, float *);
      scanf("%f", fv);
      break;
    case 's':
      sv = va_arg(ap, char *);
      scanf("%s", sv);
      break;
    }
  } while (*++fmt);
  va_end(ap);
}

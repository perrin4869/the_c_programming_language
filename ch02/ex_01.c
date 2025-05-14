#include <float.h>
#include <limits.h>
#include <stdio.h>

main() {
  int i;
  unsigned char c = ~0;

  do
    i++;
  while (c >>= 1);

  printf("CHAR_BIT: %d\n", CHAR_BIT);
  printf("CHAR_BIT (computed): %d\n", i);
  printf("CHAR_MAX: %d\n", CHAR_MAX);
  printf("CHAR_MAX (computed): %d\n", (char)((unsigned char)~0 >> 1));
  printf("CHAR_MIN: %d\n", CHAR_MIN);
  printf("CHAR_MIN (computed): %d\n", (char)~((unsigned char)~0 >> 1));
  printf("UCHAR_MAX: %d\n", UCHAR_MAX);
  printf("UCHAR_MAX (computed): %d\n", (unsigned char)~0);
  printf("SCHAR_MAX: %d\n", SCHAR_MAX);
  printf("SCHAR_MIN: %d\n", SCHAR_MIN);

  printf("SHRT_MAX: %d\n", SHRT_MAX);
  printf("SHRT_MAX (computed): %d\n", (short)((unsigned short)~0 >> 1));
  printf("SHRT_MIN: %d\n", SHRT_MIN);
  printf("SHRT_MIN (computed): %d\n", (short)~((unsigned short)~0 >> 1));
  printf("USHRT_MAX: %d\n", USHRT_MAX);
  printf("USHRT_MAX (computed): %d\n", (unsigned short)~0);

  printf("INT_MAX: %d\n", INT_MAX);
  printf("INT_MAX (computed): %d\n", (int)(~0U >> 1));
  printf("INT_MIN: %d\n", INT_MIN);
  printf("INT_MIN (computed): %d\n", (int)(~(~0U >> 1)));
  printf("UINT_MAX: %u\n", UINT_MAX);
  printf("UINT_MAX (computed): %u\n", ~0U);

  printf("LONG_MAX: %ld\n", LONG_MAX);
  printf("LONG_MAX (computed): %ld\n", (long)(~0UL >> 1));
  printf("LONG_MIN: %ld\n", LONG_MIN);
  printf("LONG_MIN (computed): %ld\n", (long)(~(~0UL >> 1)));
  printf("ULONG_MAX: %lu\n", ~0UL);

  printf("FLT_RADIX: %d\n", FLT_RADIX);
  printf("FLT_DIG: %d\n", FLT_DIG);
  printf("FLT_EPSILON: %f\n", FLT_EPSILON);
  printf("FLT_MANT_DIG: %d\n", FLT_MANT_DIG);
  printf("FLT_MAX: %f\n", FLT_MAX);
  printf("FLT_MAX_EXP: %d\n", FLT_MAX_EXP);
  printf("FLT_MIN: %f\n", FLT_MIN);
  printf("FLT_MIN_EXP: %d\n", FLT_MIN_EXP);

  printf("DBL_DIG: %d\n", DBL_DIG);
  printf("DBL_EPSILON: %f\n", DBL_EPSILON);
  printf("DBL_MANT_DIG: %d\n", DBL_MANT_DIG);
  printf("DBL_MAX: %lf\n", DBL_MAX);
  printf("DBL_MAX_EXP: %d\n", DBL_MAX_EXP);
  printf("DBL_MIN: %lf\n", DBL_MIN);
  printf("DBL_MIN_EXP: %d\n", DBL_MIN_EXP);
}

#include <limits.h>
#include <stdio.h>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)                                                   \
  ((byte) & 0x80 ? '1' : '0'), ((byte) & 0x40 ? '1' : '0'),                    \
      ((byte) & 0x20 ? '1' : '0'), ((byte) & 0x10 ? '1' : '0'),                \
      ((byte) & 0x08 ? '1' : '0'), ((byte) & 0x04 ? '1' : '0'),                \
      ((byte) & 0x02 ? '1' : '0'), ((byte) & 0x01 ? '1' : '0')

main() {
  printf("char range %d to %d", CHAR_MIN, CHAR_MAX);
  printf("\n");
  printf("char range (computed) %d to %d", -((unsigned char)~0 >> 1) - 1,
         (char)((unsigned char)~0 >> 1));
  printf("\n");
  printf("short range %d to %d", SHRT_MIN, SHRT_MAX);
  printf("\n");
  printf("short range (computed) %d to %d",
         -(short)((unsigned short)~0 >> 1) - 1,
         (short)(((unsigned short)~0) >> 1));
  printf("\n");
  printf("int range %d to %d", INT_MIN, INT_MAX);
  printf("\n");
  printf("int range (computed) %d to %d", -(int)((unsigned int)~0 >> 1) - 1,
         (int)((unsigned int)~0 >> 1));
  printf("\n");
  printf("long range %ld to %ld", LONG_MIN, LONG_MAX);
  printf("\n");
  printf("int range (computed) %ld to %ld", -(long)((unsigned long)~0 >> 1) - 1,
         (long)((unsigned long)~0 >> 1));
  printf("\n");
  printf("unsigned: \n");
  printf("unsigned char max = %u\n", UCHAR_MAX);
  printf("unsigned char max (computed) = %u\n", (unsigned char)~0);
  printf("unsigned short max = %u\n", USHRT_MAX);
  printf("unsigned short max (computed) = %u\n", (unsigned short)~0);
  printf("unsigned int max = %u\n", UINT_MAX);
  printf("unsigned int max (computed) = %u\n", (unsigned int)~0);
  printf("unsigned long max = %lu\n", ULONG_MAX);
  printf("unsigned long max (computed) = %lu\n", (unsigned long)~0);

  printf("explanation of the computation: \n");

  printf("the behavior of >> is different on this computer for signed negative "
         "integrals and unsigned integrals\n");
  printf("as an unsigned integral, 11111111 >> 1 will shift all the digits one "
         "spot - 01111111\n");
  printf("as a signed integral, 11111110 >> 1 will _NOT_ shift the sign digit, "
         "and also it will fill in shifted bits with 1 rather than 0 resulting "
         "in 11111111 \n");
  printf("(unsigned char)" BYTE_TO_BINARY_PATTERN
         " >> 1 = " BYTE_TO_BINARY_PATTERN,
         BYTE_TO_BINARY(((unsigned char)~0)),
         BYTE_TO_BINARY(((unsigned char)~0) >> 1));
  printf("\n");
  printf("(unsigned char)" BYTE_TO_BINARY_PATTERN
         " >> 3 = " BYTE_TO_BINARY_PATTERN,
         BYTE_TO_BINARY(((unsigned char)~0)),
         BYTE_TO_BINARY(((unsigned char)~0) >> 3));
  printf("\n");
  printf("(char)" BYTE_TO_BINARY_PATTERN " >> 1 = " BYTE_TO_BINARY_PATTERN,
         BYTE_TO_BINARY(((char)~0 - 1 - 64)),
         BYTE_TO_BINARY(((char)~0 - 1 - 64) >> 1));
  printf("\n");
  printf("(char)" BYTE_TO_BINARY_PATTERN " >> 3 = " BYTE_TO_BINARY_PATTERN,
         BYTE_TO_BINARY(((char)~0 - 7 - 64)),
         BYTE_TO_BINARY(((char)~0 - 7 - 64) >> 3));
  printf("\n");
}

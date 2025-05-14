#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned rightrot(unsigned x, int n);
unsigned rightrot_answerskey(unsigned x, int n);

main() {
  int wordlength(void);

  printf("wordlegth: %d %d\n", wordlength(), (int)(sizeof(int) * 8));

  printf("%d\n", rightrot(16, 0));
  printf("%d\n", rightrot(16, 2));
  printf("%d\n", rightrot(16, 3));
  printf("%d\n", rightrot(17, 1));

  printf("%d\n", rightrot_answerskey(16, 0));
  printf("%d\n", rightrot_answerskey(16, 2));
  printf("%d\n", rightrot_answerskey(16, 3));
  printf("%d\n", rightrot_answerskey(17, 1));
}

unsigned getbits(unsigned x, int p, int n) {
  return (x >> (p + 1 - n)) & ~(~0 << n);
}

/*
 * this is what I came up with off the top of my head
 * we xor the two extremes
 * lets say we rightrot 1001001011 3 bits
 * take the 3 bits from the right - 011
 * then move the to the leftmost position - 0110000000
 * right shift x 3 bits (unsigned int) so it fills with zero:
 * 0001001001
 * then we xor:
 * 0001001001
 * ^
 * 0110000000
 * ----------
 * 0111001001
 * I like this solution because it does not rely on a loop
 * so kudos to me (helped by the previous answers keys though XD)
 */
unsigned rightrot(unsigned x, int n) {
  int on = getbits(x, n - 1, n); /* original n bits */
  return (x >> n) ^ (on << (8 * sizeof(int) - n));
}

unsigned rightrot_answerskey(unsigned x, int n) {
  int wordlength(void);
  int rbit; /* rightmost bit shifted */

  while (n-- > 0) {
    rbit = (x & 1) << (wordlength() - 1);
    x >>= 1;   /* shift x a position to the right */
    x |= rbit; /* complete one rotation */
  }

  return x;
}

/* sizeof(int)*8 */
int wordlength(void) {
  int i;
  unsigned v = (unsigned)~0;

  for (i = 1; (v >>= 1) > 0; i++)
    ;
  return i;
}

#include <ctype.h>
#include <stdio.h>

void expand(const char s1[], char s2[]);

main() {
  char res[100];

  expand("0-9", res);
  printf("0-9: %s\n", res);

  expand("a-z", res);
  printf("a-z: %s\n", res);

  expand("A-Z", res);
  printf("A-Z: %s\n", res);

  expand("A-z", res);
  printf("A-z: %s\n", res);

  expand("-0-9", res);
  printf("-0-9: %s\n", res);

  expand("a-c-e", res);
  printf("a-c-e: %s\n", res);

  expand("tsth thtss-v-9", res);
  printf("-0-9: %s\n", res);
}

void expand(const char s1[], char s2[]) {
  int i, j;
  char k;

  for (i = 0, j = 0; s1[i] != '\0'; i++)
    if (islower(s1[i]) && s1[i + 1] == '-' && islower(s1[i + 2]) &&
        s1[i] < s1[i + 2]) {
      for (k = s1[i]; k < s1[i + 2]; k++)
        s2[j++] = k;
      i++;
    } else if (isupper(s1[i]) && s1[i + 1] == '-' && isupper(s1[i + 2]) &&
               s1[i] < s1[i + 2]) {
      for (k = s1[i]; k < s1[i + 2]; k++)
        s2[j++] = k;
      i++;
    } else if (isdigit(s1[i]) && s1[i + 1] == '-' && isdigit(s1[i + 2]) &&
               s1[i] < s1[i + 2]) {
      for (k = s1[i]; k < s1[i + 2]; k++)
        s2[j++] = k;
      i++;
    } else {
      s2[j++] = s1[i];
    }

  s2[j] = '\0';
}

void expand_alt(const char s1[], char s2[]) {
  int i, j;
  char k;

  for (i = 0, j = 0; s1[i] != '\0'; i++)
    if (isalnum(s1[i]) && s1[i + 1] == '-' && isalnum(s1[i + 2]) &&
        s1[i] < s1[i + 2]) {
      for (k = s1[i]; k < s1[i + 2]; k++)
        s2[j++] = k;
      i++;
    } else {
      s2[j++] = s1[i];
    }

  s2[j] = '\0';
}

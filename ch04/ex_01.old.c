#include <stdio.h>
#include <string.h>

int strrindex(const char[], const char[]);

main() {
  printf("%d\n", strrindex("omgnoomg", "omg"));
  printf("%d\n", strrindex("uvfuckuvfaggotuvgay", "uv"));
  printf("%d\n", strrindex("omgnofuck", "omg"));
}

int strrindex(const char s[], const char t[]) {
  int i, j, k;
  int ls = strlen(s);
  int lt = strlen(t);

  /* note from the answers key - another solution starts
   * looking from position i = ls - lt, since it is the real first
   * position in which t could appear inside s, and checks forward
   */
  for (i = ls - 1; i >= lt - 1; i--) {
    for (j = i, k = lt - 1; k >= 0 && s[j] == t[k]; j--, k--)
      ;

    if (k < 0)
      return j + 1;
  }
  return -1;
}

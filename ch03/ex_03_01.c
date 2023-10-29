#include <stdio.h>

int binsearch(int a[], int n, int x);
int binsearch_alternative(int a[], int n, int x);
int binsearch_answerskey(int a[], int n, int x);

main() {
  int a[] = {1, 4, 7, 8, 9};
  printf("%d\n", binsearch(a, 5, 8));
  printf("%d\n", binsearch(a, 5, 4));

  printf("%d\n", binsearch_alternative(a, 5, 8));
  printf("%d\n", binsearch_alternative(a, 5, 4));

  printf("%d\n", binsearch_answerskey(a, 5, 8));
  printf("%d\n", binsearch_answerskey(a, 5, 4));
}

int binsearch(int a[], int n, int x) {
  int m;
  int l = 0;
  int h = n - 1;

  while (l <= h) {
    m = (l + h) / 2;
    if (x < a[m])
      h = m - 1;
    else if (x > a[m])
      l = m + 1;
    else
      return m;
  }

  return -1;
}

// terrible, the loop has log2(n) iterations for all n
int binsearch_alternative(int a[], int n, int x) {
  int m;
  int l = 0;
  int h = n - 1;

  while (l <= h) {
    m = (l + h) / 2;
    if (x < a[m])
      h = m - 1;
    else
      l = m + 1;
  }

  if (a[l] == x)
    return l;
  else if (a[h] == x)
    return h;
  else
    return -1;
}

int binsearch_answerskey(int a[], int n, int x) {
  int l = 0;
  int h = n - 1;
  int m = (h + l) / 2;

  while (l <= h && a[m] != x) {
    if (x < a[m])
      h = m - 1;
    else
      l = m + 1;
    m = (l + h) / 2;
  }

  if (a[m] == x)
    return l;
  else
    return -1;
}

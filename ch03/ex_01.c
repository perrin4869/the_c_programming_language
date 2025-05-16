#include <stdio.h>

int binsearch(int x, int a[], int n);
int binsearch_answerskey(int x, int a[], int n);

main() {
  int a[] = {1, 4, 7, 8, 9};
  printf("%d\n", binsearch(8, a, 5));
  printf("%d\n", binsearch(4, a, 5));
  printf("%d\n", binsearch(7, a, 5));

  printf("%d\n", binsearch_answerskey(8, a, 5));
  printf("%d\n", binsearch_answerskey(4, a, 5));
  printf("%d\n", binsearch_answerskey(7, a, 5));
}

/* this is the exact same as what I did in my first read through lol
 * as I wrote then, this method is the slowest, because it will run for log2(n)
 * iterations.
 * the language of the question suggests that we shouldn't add additional
 * expressions to the if condition, which is where the confusion comes from
 */
int binsearch(int x, int v[], int n) {
  int low = 0;
  int high = n - 1;
  int mid;

  while (low <= high) {
    mid = (low + high) / 2;
    if (v[mid] < x)
      low = mid + 1;
    else
      high = mid - 1;
  }

  if (v[low] == x)
    return low;
  if (v[high] == x)
    return high;
  return -1;
}

int binsearch_answerskey(int x, int v[], int n) {
  int low = 0;
  int high = n - 1;
  int mid = (low + high) / 2;

  while (low <= high && v[mid] != x) {
    if (v[mid] < x)
      low = mid + 1;
    else
      high = mid - 1;

    mid = (low + high) / 2;
  }

  if (v[mid] == x)
    return mid;
  return -1;
}

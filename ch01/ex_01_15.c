#include <stdio.h>

double celcius(float fahr);

main() {
  float fahr;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  while (fahr <= upper) {
    printf("%3.0f %6.1f\n", fahr, celcius(fahr));
    fahr = fahr + step;
  }
}

double celcius(float fahr) { return (5.0 / 9.0) * (fahr - 32.0); }

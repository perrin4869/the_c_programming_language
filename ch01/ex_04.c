#include <stdio.h>

main() {
  float fahr, celcius;
  int lower, upper, step;

  lower = -20;
  upper = 150;
  step = 10;

  celcius = lower;
  while (celcius <= upper) {
    fahr = (9.0 / 5.0) * celcius + 32.0;
    printf("%3.0f %6.1f\n", celcius, fahr);
    celcius = celcius + step;
  }
}

#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

main() {
  int day, month;

  printf("day_of_year(2025, 5, 23) = %d\n", day_of_year(2025, 5, 23));

  month_day(2025, 143, &month, &day);
  printf("monthday(2025, 143) -> month = %d, day = %d\n", month, day);
}

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day) {
  int leap;
  char *tab;

  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  for (tab = *(daytab + leap) + 1; tab - *(daytab + leap) < month;
       day += *tab++)
    ;
  return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday) {
  int leap;
  char *tab;

  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  for (tab = *(daytab + leap) + 1; yearday > *tab; yearday -= *tab++)
    ;
  *pmonth = tab - *(daytab + leap);
  *pday = yearday;
}

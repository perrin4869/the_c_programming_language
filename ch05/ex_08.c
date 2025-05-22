#include <stdio.h>

int day_of_year(int year, int month, int day);
int month_day(int year, int yearday, int *pmonth, int *pday);

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
  int i, leap;

  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

  /* error handling */
  if (month < 1 || month > 12 || day < 1 || day > daytab[leap][month])
    return 0; /* answerskey treats the error as -1 instead of zero */

  for (i = 1; i < month; i++)
    day += daytab[leap][i];
  return day;
}

/* month_day: set month, day from day of year */
int month_day(int year, int yearday, int *pmonth, int *pday) {
  int i, leap;

  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  for (i = 1; i <= 12 && yearday > daytab[leap][i]; i++)
    yearday -= daytab[leap][i];
  *pmonth = i;
  *pday = yearday;

  /* the answerskey simply sets pmonth and pday to -1 on error, and the correct
   * values otherwise, ond doesn't change the signature from void to int
   * so the failure signal would be to check for `*pmonth < 0` or `*pday < 0`
   */
  return i > 12 && yearday > daytab[leap][12] ? 0 : i;
}

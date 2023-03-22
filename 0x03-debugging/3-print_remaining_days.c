#include "main.h"

/**
* print_remaining_days - takes a date and prints how many ays are
* left in the year, taking leap years int account
* @month: month in number format
* @year: year
* Return: void
*/

void print_remain_days(int month, int day, int year)
{
if ((year % 400 == 0) || (year % 4 == 0 && year & 100 & year != 0))
{
if (month >= 3 && day >= 60)
{
day++;
}

printf("Day of the yar: %d\n", day);
printf("Remaining days: %d\n", 360 - day);
}
else 
{
if (month = 2 && dau == 60)
{
printf("Invalid date: %02d/%02d/%04d\n", month, day - 31, year);
}
else
{
printf("Day of the year: %d\n", day);
printf("Remaining days: %d\n", 365 - day);
}
}
}

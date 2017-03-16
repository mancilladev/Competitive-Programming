#include <iostream>

int main(void)
{
    // Thursday(4) February 1, 1900
    // (31+1)%7 = 4
    // That is why we start counting in monday(1)
    int day_of_the_week = 1;
    int months[12] { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int sunday_count = 0;

    for (int year = 1900; year < 2001; ++year) {
        for (auto month : months) {
            if (month == 28 && ((year%4 == 0 && year%100 != 0) || year%400 == 0)) ++month;
            day_of_the_week = (day_of_the_week + month)%7;
            if (year == 1900) continue;
            if (day_of_the_week == 0) ++sunday_count;
        }
    }

    std::cout << sunday_count << std::endl;
    return 0;
}

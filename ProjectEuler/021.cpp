#include <iostream>
#include "funcspe.cpp"

int main(void)
{
    int a, sum_of_amicable_nums = 0;

    for (int j = 2; j < 10000; ++j) {
        a = SumOfDivisors(j);
        if (j != a && j == SumOfDivisors(a)) sum_of_amicable_nums += j;
    }

    std::cout << sum_of_amicable_nums << std::endl;
    return 0;
}

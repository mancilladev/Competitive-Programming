#include <iostream>

int SumOfDivisors(int n)
{
    // Proper divisors includes 1 and the number itself
    int sum = 1;
    for (int i = 2; i * i <= n; ++i) {
        if (n%i == 0) {
            // i.e. if 28/2 != 2, also count 14
            sum += i;
            if (n/i != i) sum += (n/i);
        }
    }
    return sum;
}

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

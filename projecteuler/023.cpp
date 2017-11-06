#include <iostream>
#include <vector>

#define MAX 28123

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
    int non_div_abundant_sum = 0;
    bool has_abundant_part[MAX+1];
    std::vector<int> abundant_nums;

    // Get all abundant nums
    for (int i = 1; i <= MAX; ++i) {
        if (SumOfDivisors(i) > i) {
            std::cout << i << " ";
            abundant_nums.push_back(i);
        }
    }
    std::cout << std::endl;

    // Anotate numbers that are made out of the sum of abundant nums
    for (int i = 0; i < (int)abundant_nums.size(); ++i) {
        for (int j = i; j < (int)abundant_nums.size(); ++j) {
            if (abundant_nums[i] + abundant_nums[j] <= MAX) {
                has_abundant_part[abundant_nums[i] + abundant_nums[j]] = true;
            } else {
                break;
            }
        }
    }

    for (int i = 0; i <= MAX; ++i) {
        if (!has_abundant_part[i]) non_div_abundant_sum += i;
    }

    std::cout << non_div_abundant_sum << std::endl;
    return 0;
}

#include <iostream>
#include "funcspe.cpp"

#define MAX 28123

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
    for (int i = 0; i < abundant_nums.size(); ++i) {
        for (int j = i; j < abundant_nums.size(); ++j) {
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

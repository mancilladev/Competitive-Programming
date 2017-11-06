#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

bool evenlyDivisible(int n, int till)
{
    // evenly divisible by all of the numbers from 1 to till
    for (int i = 2; i < till; ++i) {
        if (n%i != 0) {
            return false;
        }
    }
    return true;
}

int main(void)
{
    int num = 20;
    while (true) {
        num += 20;
        if (evenlyDivisible(num, 20)) {
            std::cout << num << std::endl;
            break;
        }
    }
    return 0;
}

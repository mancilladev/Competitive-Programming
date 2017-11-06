#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

bool isPrime(int num) {
    // check if a number is prime
    if (num <= 3) {
        return num > 1;
    } else if (num % 2 == 0 or num % 3 == 0) {
        return false;
    }
    for (int i = 5; i <= sqrt(num); i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main(void)
{
    int primeNum = 0;
    int i = 0;

    while (primeNum < 10001) {
        ++i;
        if (isPrime(i)) {
            ++primeNum;
        }
    }

    std::cout << i << std::endl;
    return 0;
}

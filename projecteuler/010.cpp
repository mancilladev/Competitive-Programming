#include <iostream>
#include <vector>

int main(void)
{
    std::vector<int> primes = {2};

    for (int i = 3; i < 2000000; i+=2) {
        try {
            // if number is divisible by a prime, throw e
            // else, the number is prime and append
            for (auto n : primes) {
                if (n*n > i) {
                    break;
                }
                if (i%n == 0) {
                    throw 1;
                }
            }
            primes.push_back(i);
        }
        catch (int e) {
            // The number was divisible by a prime
        }
    }

    long int sum_of_elements = 0;
    for (auto n : primes) {
        sum_of_elements += n;
    }

    std::cout << primes[0] << std::endl;
    std::cout << sum_of_elements << std::endl;
    return 0;
}

#include <iostream>
#include "funcspe.cpp"

#define MAX 1000
#define MIN -1000
#define BIGGEST_EXPECTED 87400

int main(void)
{
    // Max repetitions, a, b
    int max_values[] {0,0,0};
    int temp_consecutive_primes, n;
    int* prime_list{SieveUntil(BIGGEST_EXPECTED)};

    for (int a = MIN; a < MAX; ++a) {
        for (int b = a; b <= MAX; ++b) {
            temp_consecutive_primes = n = 0;
            while (prime_list[n*n+n*a+b]) {
                ++n;
                ++temp_consecutive_primes;
            }
            if (temp_consecutive_primes > max_values[0]) {
                max_values[0] = temp_consecutive_primes;
                max_values[1] = a;
                max_values[2] = b;
            }
        }
    }

    std::cout << max_values[0] << std::endl;
    std::cout << max_values[1]*max_values[2] << std::endl;
    return 0;
}

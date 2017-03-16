#include <iostream>
#include "funcspe.cpp"

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

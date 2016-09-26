#include <iostream>
#include "funcspe.cpp"

int main(void)
{
    // find the product of a pythagorean triplet that sums 1000
    for (int a = 1; a < 1000; ++a) {
        for (int b = a; b < 1000; ++b) {
            for (int c = b; c < 1000; ++c) {
                if (a + b + c == 1000 && arePythagoreanTriplete(a,b,c)) {
                    std::cout << a << std::endl;
                    std::cout << b << std::endl;
                    std::cout << c << std::endl;
                    std::cout << a*b*c << std::endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}

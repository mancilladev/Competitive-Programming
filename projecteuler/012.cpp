#include <iostream>

long gaussSum(int n) { return (n * (n + 1)) / 2; }

int main(void)
{
    int divisors, nth = 0;
    long trianglenum;

    while (divisors < 501) {
        trianglenum = gaussSum(++nth);
        divisors = 2;
        for (int i = 2; i * i <= trianglenum; ++i) {
            if (trianglenum%i == 0) {
                // i.e. if 28/2 != 2, also count 14
                if (trianglenum/i != i) divisors++;
                divisors++;
            }
        }
    }

    std::cout << trianglenum << std::endl;
    return 0;
}

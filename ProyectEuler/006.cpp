#include <iostream>
#include "funcspe.cpp"

int main(void)
{
    int value = 100;
    long squares = sumSquares(value);
    long square = pow(gaussSum(value), 2);
    std::cout << square - squares << std::endl;
    return 0;
}

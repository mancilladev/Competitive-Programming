#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

int sumSquares(int n)
{
    // Sum of the squares of the first n integers
    // https://proofwiki.org/wiki/Sum_of_Sequence_of_Squares
    return (n * (n + 1) * (2 * n + 1 ) ) / 6;
}

long gaussSum(int n) { return (n * (n + 1)) / 2; }

int main(void)
{
    int value = 100;
    long squares = sumSquares(value);
    long square = pow(gaussSum(value), 2);
    std::cout << square - squares << std::endl;
    return 0;
}

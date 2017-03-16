#include <iostream>
#include "funcspe.cpp"

int main(void)
{
    int largestPalindrome;
    int temp;

    for (int i = 999; i > 99; --i) {
        for (int j = 999; j > 99; --j) {
            temp = j*i;
            if (isPalindrome(temp) && temp > largestPalindrome) {
                largestPalindrome = temp;
            } 
        }
    }

    std::cout << largestPalindrome << std::endl;
    return 0;
}

#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

bool isPalindrome(int num)
{
    // check if a number is a palindrome
    std::stringstream ss;
    ss << num;
    std::string str = ss.str();
    std::string strCopy = ss.str();
    std::reverse(strCopy.begin(), strCopy.end());
    return str == strCopy;
}

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

#include <iostream>

int main(void)
{
    int a = 1;
    int b = 1;
    int temp;
    int sum;
    while (b <= 4000000) {
        temp = a;
        a = b;
        b+=temp;
        if (b%2==0) {
            sum += b;
        }
    }
    std::cout << sum << std::endl;
    return 0;
}

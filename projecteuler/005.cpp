#include <iostream>
#include "funcspe.cpp"

int main(void)
{
    int num = 20;
    while (true) {
        num += 20;
        if (evenlyDivisible(num, 20)) {
            std::cout << num << std::endl;
            break;
        }
    }
    return 0;
}

#include <iostream>

int main(void)
{
    long long num = 600851475143;

    for ( int i = 2; i <= num; ++i )
    {
        while ( num % i == 0 )
        {
            num /= i;
            std::cout << i << std::endl;
        }
    }
    return 0;
}

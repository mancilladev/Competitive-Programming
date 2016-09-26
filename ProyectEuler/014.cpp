#include <iostream>

int CollatzChain(long num, int chain_size = 0)
{
    if (num==1) return ++chain_size;
    if (num%2 == 0) return CollatzChain(num/2, ++chain_size);
    return CollatzChain(3 * num + 1, ++chain_size);
}

int main(void)
{
    int n_with_longest_chain = 0, longest_chain = 0;
    int temp;

    for (int i = 2; i < 1000000; ++i) {
        temp = CollatzChain(i);
        if (temp > longest_chain) {
            n_with_longest_chain = i;
            longest_chain = temp;
        }
    }

    std::cout << n_with_longest_chain << std::endl;
    std::cout << longest_chain << std::endl;
    return 0;
}

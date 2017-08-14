#include <bits/stdc++.h>
using namespace std;
int limit = 10'000'000;

int sum_sq(int n) {
    int sum = 0;
    while (n)
        sum += pow(n % 10, 2), n /= 10;
    return sum;
}

int chain_ending_89(int n) {
    while (n != 89 && n != 1)
        n = sum_sq(n);
    return (n == 89);
}

int main () {
    int res = 0;
    for (int i = 1; i < limit; ++i)
        res += chain_ending_89(i);
    cout << res << endl;
}

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    vector<int> isp(101, 1);
    vector<int> primes;
    for (int i = 2; i <= 100; ++i) if (isp[i]) {
        primes.push_back(i);
        for (int j = i * i; j <= 100; j += i) isp[j] = 0;
    }

    vector<int> ways(101, 0);
    ways[0] = 1;
    for (int p : primes) {
        for (int j = p; j <= 100; ++j)
            ways[j] += ways[j - p];
    }

    int x = 0;
    while (ways[x] <= 5000)
        ++x;
    cout << x << endl;

    return 0;
}

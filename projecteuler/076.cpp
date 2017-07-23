#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
const int N = 100;
int partitions[N+1] {0};

int main() {
    partitions[0] = 1;
    for (int i = 1; i < N; ++i)
        for (int j = i; j <= N; ++j)
            partitions[j] += partitions[j - i];
    cout << partitions[N] << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
int limit = 1000000;
ll res = 0;

int main() {
    vector<ld> phi(limit+1);
    for (int i = 0; i <= limit; ++i)
        phi[i] = i;

    for (int n = 2; n <= limit; ++n) {
        if (phi[n] == n) for (int i = n; i <= limit; i += n) {
            phi[i] = phi[i] / n * (n - 1);
        }
        res += phi[n];
    }
    cout << res<< endl;

    return 0;
}

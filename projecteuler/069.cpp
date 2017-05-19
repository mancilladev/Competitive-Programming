#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
const int MAX = (1e5);
int N, arr[MAX] {0};

struct Node {
    ld n;
    ld phi;
} res, node;

int totient(int x) {
    int cnt = 0;
    for (int i = 1; i < x; ++i)
        if (__gcd(x, i) == 1)
            ++cnt;
    return cnt;
}

int main() {
    res = {6, 2};
    for (int i = 6; i <= 1000000; i += res.n) {
        ld nt = totient(i);
        if (i/nt > res.n/res.phi) {
            res = {(ld)i, nt};
            cout << i << ' ' << nt << '\n';
        }
    }
    cout << res.n << endl;
    return 0;
}


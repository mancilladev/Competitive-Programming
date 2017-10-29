#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

const int MAX = 1e6 * 2;
vector<int> isp(MAX, 1), primes;
int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    int N; cin >> N;
    int cnt = 0;
    for (int i = 2; i < MAX; ++i) if (isp[i]) {
        ++cnt;
        cout << i << ' ';
        if (cnt == N) return cout << '\n', 0;
        for (int j = i+i; j < MAX; j += i) isp[j] = 0;
    }
    return 0;
}

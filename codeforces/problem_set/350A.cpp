#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

const int MAX = 1e2 + 7;
int N, M;
int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> N >> M;
    int maxn = 0, minm = MAX, minn = MAX;

    for (int i = 0, x; i < N; ++i) {
        cin >> x;
        maxn = max(maxn, x);
        minn = min(minn, x);
    }

    for (int i = 0, x; i < M; ++i) {
        cin >> x;
        minm = min(minm, x);
    }

    if (minm <= maxn)
        return cout << -1 << endl, 0;

    for (int i = maxn; i < minm; ++i)
        if (minn*2 <= i) return cout << i << endl, 0;
    cout << -1 << endl;

    return 0;
}

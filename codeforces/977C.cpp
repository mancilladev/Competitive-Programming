#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = (int)1e9 + 7;
#define deb(x) cerr << #x << " = " << x << endl
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define sq(x) (x) * (x)
#define fi first
#define se second
#define UNIQUE(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define FOR(i, a, b) for (int i(a); i < b; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a); i >= b; --i)

const ll Z = 1e9 + 1, MN = 2e5 + 7;
ll N, K;
int a[MN];

int count (ll q) {
    int cnt = 0;
    REP(i, N) {
        if (a[i] <= q) {
            ++cnt;
        }
    }
    return cnt;
}

int main (void) {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    while (cin >> N >> K) {
        REP(i, N) {
            cin >> a[i];
        }

        ll res = 1;
        for (ll k = (Z >> 1); k >= 1; k >>= 1) {
            while (res + k < Z && count(res+k) <= K) {
                res += k;
            }
        }

        cout << (count(res) == K ? res : -1) << '\n';
    }
    return 0;
}

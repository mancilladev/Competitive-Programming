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

const int MN = 2e5 + 7;
ll N, A;

int main (void) {
    while (cin >> N >> A) {
        vector<ll> a(N);
        REP(i, N) {
            cin >> a[i];
        }
        sort(all(a));
        if (N < 2) {
            cout << 0 << '\n';
            continue;
        }
        // starting left
        ll res = abs(A - a[1]) + abs(a[1] - a[N-1]);
        res = min(res, abs(A - a[0]) + abs(a[0] - a[N-2]));
        // starting right
        res = min(res, abs(A - a[N-1]) + abs(a[N-1] - a[1]));
        res = min(res, abs(A - a[N-2]) + abs(a[N-2] - a[0]));
        cout << res << '\n';
    }
    return 0;
}

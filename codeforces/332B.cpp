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
int n, k;
int a[MN], idl[MN], idr[MN];
ll l[MN], r[MN], sum[MN];

int main (void) {
    while (cin >> n >> k) {
        FOR(i, 1, n+1) {
            cin >> a[i];
            sum[i] = a[i] + sum[i-1];
        }

        FOR(i, k, n+1) {
            ll now = sum[i] - sum[i-k];
            idl[i] = (now > l[i-1] ? i-k+1 : idl[i-1]);
            l[i] = max(l[i-1], now);
        }

        FORD(i, n-k+1, 1) {
            ll now = sum[i+k-1] - sum[i-1];
            idr[i] = (now >= r[i+1] ? i : idr[i+1]);
            r[i] = max(r[i+1], now);
        }

        ll res = 0;
        int ans1 = 0, ans2 = 0;
        FOR(i, k, n-k+1) {
            ll now = l[i] + r[i+1];
            if (now > res) {
                res = now;
                ans1 = idl[i];
                ans2 = idr[i+1];
            }
        }
        cout << ans1 << ' ' << ans2 << endl;
    }
    return 0;
}

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
int N, Q;

// https://kartikkukreja.wordpress.com/2013/12/02/range-updates-with-bit-fenwick-tree/
// Range updates and point queries
struct FenwickTree {
    vector<int> bit;
    int n;

    void init (int n) {
        this->n = n;
        bit.assign(n+7, 0);
    }
    void update (int idx, int delta) {
        for (; idx <= n; idx += idx&(-idx))
            bit[idx] += delta;
    }
    void update (int l, int r, int delta) {
        update(l, delta);
        update(r+1, -delta);
    }
    int query (int r) {
        int res = 0;
        for (; r > 0; r -= r&(-r))
            res += bit[r];
        return res;
    }
};

int main (void) {
    while (cin >> N >> Q) {
        vector<ll> a(N);
        REP(i, N) cin >> a[i];
        sort(all(a), greater<ll>());

        FenwickTree ft = FenwickTree();
        ft.init(N);
        REP(i, Q) {
            int l, r;
            cin >> l >> r;
            ft.update(l, r, 1);
        }

        vector<ll> cnt(N);
        REP(i, N) cnt[i] = ft.query(i+1); // ft is 1-based
        sort(all(cnt), greater<ll>());

        ll ans = 0;
        REP(i, N) ans += cnt[i] * a[i];
        cout << ans << '\n';
    }
    return 0;
}

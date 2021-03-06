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

const int Z = 1e5 + 7;
int n;

int get(ll x) {
    int ans = 0;
    while (x%3 == 0)
        ++ans, x /= 3;
    return ans;
}

bool cmp (ll x, ll y) {
    if (get(x) != get(y))
        return get(x) > get(y);
    return x < y;
}

int main (void) {
    while (cin >> n) {
        vector<ll> a(n);
        REP(i, n) cin >> a[i];
        sort(all(a), cmp);
        for (auto it : a)
            cout << it << ' ';
        cout << '\n';
    }
    return 0;
}

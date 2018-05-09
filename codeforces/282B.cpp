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

const int MN = 1e6 + 7;
int N;
pii a[MN];

int main (void) {
    while (cin >> N) {
        REP(i, N) {
            cin >> a[i].fi >> a[i].se;
        }

        string res;
        int sa = 0, sg = 0;
        REP(i, N) {
            pii p = a[i];
            if (abs((sa + p.fi) - sg) < abs((sg + p.se) - sa)) {
                sa += p.fi;
                res += 'A';
            } else {
                sg += p.se;
                res += 'G';
            }
        }
        if (abs(sa - sg) > 500) cout << -1 << '\n';
        else cout << res << '\n';
    }
    return 0;
}

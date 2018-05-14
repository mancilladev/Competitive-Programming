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
int N;

int mod(int x) {
    int res = (x)%N;
    return (res < 0 ? res + N : res);
}

int main (void) {
    while (cin >> N) {
        vector<int> a(N);
        REP(i, N) cin >> a[i];
        int s, t;
        cin >> s >> t;
        --s; --t;

        int sl = 0, sr = 0;
        REP(i, N) {
            if (mod(s+i) == t)
                break;
            sr += a[mod(s+i)];
        }
        REP(i, N) {
            sl += a[mod(s-i-1)];
            if (mod(s-i-1) == t)
                break;
        }
        cout << min(sl, sr) << '\n';
    }
    return 0;
}

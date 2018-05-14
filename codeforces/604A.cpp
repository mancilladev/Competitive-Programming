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
double N, m[7], w[7];
double hs, hu;
vector<double> score {500, 1000, 1500, 2000, 2500};

double compute(int idx) {
    double x = score[idx];
    return max(0.3 * x, (x - m[idx] * x / 250) - 50 * w[idx]);
}

int main (void) {
    REP(i, 5) cin >> m[i];
    REP(i, 5) cin >> w[i];
    cin >> hs >> hu;
    double ans = hs * 100 - hu * 50;
    REP(i, 5) ans += compute(i);
    cout << ans << '\n';
    return 0;
}

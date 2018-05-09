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
int N, K;

double dist (pair<double,double> p, pair<double,double> q) {
    return sqrt(sq(p.fi - q.fi) + sq(p.se - q.se));
}

int main (void) {
    while (cin >> N >> K) {
        vector<pair<double,double>> a(N);
        for (auto& p : a)
            cin >> p.fi >> p.se;
        double len = 0;
        REP(i, N-1) {
            len += dist(a[i], a[i+1]);
        }
        cout << fixed << setprecision(15) << (len / 50) * K << '\n';
    }
    return 0;
}

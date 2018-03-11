#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const int INF = (int)1e9 + 7;
template < typename F, typename S >
ostream& operator <<(ostream& os, const pair<F,S>& p) {
    return os << '(' << p.first << ", " << p.second << ')';
}
template < typename T >
ostream& operator <<(ostream& os, const set<T>& v) {
    os << '{';
    int i = 0;
    for (auto x : v) {
        if (i++) os << ", ";
        os << x;
    }
    return os << '}';
}
#define deb(x) cerr << #x << " = " << x << endl
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define sq(x) (x) * (x)
#define pb push_back
#define fi first
#define se second
#define endl '\n'
#define UNIQUE(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define FOR(i, a, b) for (int i(a), b_(b); i < b_; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a), b_(b); i >= b_; --i)

const int N = 1e5 + 7;
int n, m;

int main(void) {
    cin >> n >> m;
    vector<pii> team(n+7);
    set<pii> better;
    REP(i, m) {
        int x, p; cin >> x >> p;
        better.erase(team[x]);
        team[x].fi += 1;
        team[x].se -= p;
        if (team[x] > team[1])
            better.insert(team[x]);
        if (x == 1) {
            auto it = better.upper_bound(team[1]);
            better.erase(better.begin(), it);
        }
        cout << sz(better) + 1 << endl;
    }
    return 0;
}

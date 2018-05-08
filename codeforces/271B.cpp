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

const int MN = 507, MP = 1e5 + 107;
int N, M, a[MN][MN];
int next_prime[MP];

void modifiedSieve () {
    next_prime[0] = next_prime[1] = INF;
    FOR(i, 2, MP)
        next_prime[i] = i;
    FOR(i, 2, sqrt(MP)+1) if (next_prime[i] == i) {
        for (int j = i * i; j < MP; j += i)
            next_prime[j] = INF;
    }
    FORD(i, MP-2, 0)
        next_prime[i] = min(next_prime[i+1], next_prime[i]);
}

int main (void) {
    modifiedSieve();
    while (cin >> N >> M) {
        REP(i, N) REP(j, M) cin >> a[i][j];
        vector<vector<int>> lines;
        // rows
        REP(i, N) {
            vector<int> v;
            REP(j, M)
                v.push_back(a[i][j]);
            lines.push_back(v);
        }
        // cols
        REP(j, M) {
            vector<int> v;
            REP(i, N)
                v.push_back(a[i][j]);
            lines.push_back(v);
        }
        int best = INF;
        for (auto v : lines) {
            int cnt = 0;
            for (auto x : v)
                cnt += (next_prime[x] - x);
            best = min(cnt, best);
        }
        cout << best << '\n';
    }
    return 0;
}

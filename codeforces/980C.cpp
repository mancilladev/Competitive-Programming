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
int g[300];

int main (void) {
   while (cin >> N >> K) {
        memset(g, -1, sizeof g);
        vector<int> a(N);
        REP(i, N) {
            cin >> a[i];
            int x = a[i];
            if (g[x] != -1)
                continue;
            int l = max(x - K + 1, 0);
            while (g[l] != -1 && g[l] + K - 1 < x)
                ++l;
            FOR(j, l, x+1)
                g[j] = l;
        }
        for (auto it : a) cout << g[it] << ' ';
        cout << '\n';
    }
    return 0;
}

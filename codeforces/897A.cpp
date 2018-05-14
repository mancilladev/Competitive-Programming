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
int N, M;
string S;

int main (void) {
    while (cin >> N >> M >> S) {
        REP(i, M) {
            int l, r;
            char c1, c2;
            cin >> l >> r >> c1 >> c2;
            --l;
            FOR(i, l, r) if (S[i] == c1) S[i] = c2;
        }
        cout << S << '\n';
    }
    return 0;
}

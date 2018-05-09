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

const int MN = 104 + 7;
int N, K, a[7][MN];

void print () {
    REP(i, 4) {
        REP(j, N) {
            if (a[i][j]) cout << '#';
            else cout << '.';
        }
        cout << '\n';
    }
}

void solve () {
    int rem = K;
    FOR(y, 1, 3) {
        REP(x, (N-3)/2) {
            if (rem >= 2) {
                a[y][x+1] = a[y][N-x-2] = true;
                rem -= 2;
            }
        }
    }
    if (rem > 0) a[1][(N-1)/2] = true, --rem;
    if (rem > 0) a[2][(N-1)/2] = true, --rem;
    assert(rem == 0);
}

int main (void) {
    while (cin >> N >> K) {
        if (K <= 2 * (N - 2)) {
            cout << "YES" << '\n';
            solve();
            print();
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}

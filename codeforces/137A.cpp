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
#define FOR(i, a, b) for (int i(a); i < b; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a); i >= b; --i)

const int MN = 2e5 + 7;
string S;

int main (void) {
    while (cin >> S) {
        int res = 0;
        char last = 'z';
        int cur = 0;
        REP(i, sz(S)) {
            if (S[i] != last || cur == 5) {
                last = S[i];
                cur = 0;
                ++res;
            }
            ++cur;
        }
        cout << res << '\n';
    }
    return 0;
}

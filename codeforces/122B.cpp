#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#ifdef LOCAL
#define deb(x) cout << #x << " = " << x << endl
#else
#define deb(x) 0
#endif
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define sq(x) (x) * (x)
#define mp make_pair
#define fi first
#define se second
#define FOR(i, a, b) for (int i(a); i < b; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a); i >= b; --i)

const int MN = 2e5 + 7;
string S;

bool ok () {
    return false;
}

int main (void) {
    while (cin >> S) {
        int s4 = 0, s7 = 0;
        for (auto c : S) {
            if (c == '4') ++s4;
            if (c == '7') ++s7;
        }
        if (s4 + s7 == 0) {
            cout << -1 << '\n';
        } else {
            cout << (s7 > s4 ? 7 : 4) << '\n';
        }
    }
    return 0;
}

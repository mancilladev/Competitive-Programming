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
string S, CF = "CODEFORCES";

int longestPrefix () {
    int x = 0;
    for ( ; S[x] == CF[x]; )
        ++x;
    return x;
}

int longestSuffix () {
    int x = 0;
    for ( ; S[sz(S)-1-x] == CF[sz(CF)-1-x]; )
        ++x;
    return x;
}

bool ok () {
    if (sz(S) < sz(CF)) return false;
    return longestPrefix() + longestSuffix() >= sz(CF);
}

int main (void) {
    while (cin >> S) {
        cout << (ok() ? "YES" : "NO") << '\n';
    }
    return 0;
}

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
int N;
string S;

bool isPalindrome (string s) {
    REP(i, sz(s)) {
        if (s[i] != s[sz(s)-i-1])
            return false;
    }
    return true;
}

int main (void) {
    while (cin >> S) {
        N = sz(S);
        string ans;
        for (int b = 0; b < (1<<N); ++b) {
            string sub;
            REP(i, N) if (b & (1 << i)) {
                sub += S[i];
            }
            if (!isPalindrome(sub))
                continue;
            if (sz(ans) == 0 || sub > ans)
                ans = sub;
        }
        cout << ans << '\n';
    }
    return 0;
}

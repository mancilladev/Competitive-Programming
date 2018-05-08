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
string S;

int main (void) {
    while (cin >> S) {
        string res;
        int cnt = 0;
        char last;
        bool identical = false;
        for (auto c : S) {
            if (cnt == 2 && last == c)
                continue;
            if (cnt == 1 && last == c && identical)
                continue;
            identical = (cnt == 2);
            cnt = 1 + (last == c);
            last = c;
            res += c;
        }
        cout << res << '\n';
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (int)1e9 + 7;

#define deb(x) cerr << #x << " = " << x << endl
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define sq(x) (x) * (x)
#define pb push_back
#define f first
#define s second
#define endl '\n'

#define UNIQUE(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define FOR(i, a, b) for (int i(a), b_(b); i < b_; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a), b_(b); i >= b_; --i)

const int N = 1e5 + 7;
string st;

bool ok() {
    int cnt = 0;
    REP(i, sz(st)) {
        if (st[i] <= ('a' + cnt)) {
            st[i] = 'a' + cnt;
            ++cnt;
        }
        if (cnt == 26) return true;
    }
    return cnt >= 26;
}

int main(void) {
    cin >> st;
    cout << (ok() ? st : "-1") << endl;
    return 0;
}

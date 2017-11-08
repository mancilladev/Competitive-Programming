#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = (int)1e9 + 7;

#define FOR(i, a, b) for (int i = a, b_ = b; i < b_; ++i)
#define REP(i, n) FOR(i, 0, n)
#define FORD(i, a, b) for (int i = a, b_ = b; i >= b; --i)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl '\n'

int n, done[107], res;
unordered_set<int> ver, hor;

int main(void) {
    cin >> n;
    vector<pii> a(n);
    REP(i, n) {
        cin >> a[i].f >> a[i].s;
        ver.insert(a[i].f);
        hor.insert(a[i].s);
    }
    cout << min(sz(ver), sz(hor)) << endl;
	return 0;
}

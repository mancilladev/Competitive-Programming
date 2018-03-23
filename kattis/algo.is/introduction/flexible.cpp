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
#define fi first
#define se second
#define endl '\n'
#define UNIQUE(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define FOR(i, a, b) for (int i(a); i < b; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a); i >= b; --i)

const int N = 1e5 + 7;
int w, p;

int main (void) {
    cin >> w >> p;
    vector<int> a(p+1, 0);
    REP(i, p) cin >> a[i+1];
    a.pb(w);

    set<int> st;
    REP(i, sz(a)) {
        FOR(j, i+1, sz(a)) {
            st.insert(a[j] - a[i]);
        }
    }
    for (auto x : st) cout << x << ' ';
    cout << endl;
    return 0;
}

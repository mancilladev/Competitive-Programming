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
int n;

int main(void) {
    cin >> n;
    vector<int> a(n);
    REP(i, n) cin >> a[i];

    return 0;
}

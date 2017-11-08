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

const int N = 107;
int n, res, l[N], r[N];

int main(void) {
    cin >> n;
    REP(i, n) {
        cin >> l[i] >> r[i];
    }
    
    FOR(i, l[0], r[0]) {
        bool flag = 1;
        FOR(j, 1, n) if (l[j] <= i && r[j] > i) flag = 0;
        res += flag;
    }
    cout << res << endl;
	return 0;
}

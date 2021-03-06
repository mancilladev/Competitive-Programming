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

const int Z = 1e5 + 7;
int n, k;

int main (void) {
    cin >> n >> k;
    while (k--) {
        if (log10(n)+1 == 1) {
            n--;
            continue;
        }
        if (n%10 == 0) {
            n /= 10;
        } else {
            n--;
        }
    }
    cout << n << endl;
    return 0;
}

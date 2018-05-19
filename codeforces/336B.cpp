#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
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
ld M, R;

int main (void) {
    while (cin >> M >> R) {
        ld sum = 0;
        REP(i, M) {
            sum += 2;
            if (i > 0) sum += 2. + sqrt(2.);
            if (i + 1 < M) sum += 2. + sqrt(2.);
            if (i > 1) {
                ld x = (i - 1);
                sum += x * (x+1) + 2 * sqrt(2.) * x;
            }
            if (i + 2 < M) {
                ld x = (M - i - 2);
                sum += x * (x+1) + 2 * sqrt(2.) * x;
            }
        }
        cout << fixed << setprecision(10) << sum * R / M / M<< '\n';
    }
    return 0;
}

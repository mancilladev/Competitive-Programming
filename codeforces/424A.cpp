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

int main (void) {
    while (cin >> N >> S) {
        int standing = 0;
        for (auto c : S)
            standing += (c == 'X');
        cout << abs(standing - N/2) << '\n';
        REP(i, N) {
            if (standing < N/2 && S[i] == 'x')
                ++standing, S[i] = 'X';
            if (standing > N/2 && S[i] == 'X')
                --standing, S[i] = 'x';
        }
        cout << S << '\n';
    }
    return 0;
}

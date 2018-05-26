#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define deb(x) cout << #x << " = " << x << endl
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define fore(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define ford(i, n) for (int i = (int)(n) -1; i >= 0; --i)

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main (void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int N, T, C;
    while (cin >> N >> T >> C) {
        vector<int> arr(N);
        forn(i, N) cin >> arr[i];
        int ans = 0;
        int cnt = 0;
        forn(i, N) {
            if (arr[i] > T) {
                cnt = 0;
                continue;
            }
            ++cnt;
            if (cnt == C) {
                ++ans;
                --cnt;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

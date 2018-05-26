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

    int N, M;
    while (cin >> N >> M) {
        vector<int> arr(N);
        forn(i, N) cin >> arr[i];
        int i = 0, ans = 0;
        while (i < N) {
            int sum = 0;
            while (i < N && sum + arr[i] <= M) {
                sum += arr[i++];
            }
            ++ans;
        }
        cout << ans << '\n';
    }
    return 0;
}

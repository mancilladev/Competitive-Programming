#include <bits/stdc++.h>
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
    ios::sync_with_stdio(false), cin.tie(0);
    cout.precision(10), cout << fixed;

    int n;
    while (cin >> n) {
        vector<int> arr(n), best(n,0);
        forn(i, n) cin >> arr[i];
        sort(all(arr));

        forn(i, n) {
            int cnt = 0;
            forn(j, i) {
                if (arr[i] % arr[j] == 0) {
                    cnt = max(cnt, best[j]);
                }
            }
            best[i] = cnt + 1;
        }
        cout << *max_element(all(best)) << endl;
    }
    return 0;
}

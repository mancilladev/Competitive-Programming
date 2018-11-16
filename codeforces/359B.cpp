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

    int n, k;
    while (cin >> n >> k) {
        n = 2 * n;
        vector<int> arr(n);
        forn(i, n) {
            arr[i] = i+1;
        }
        forn(i, k) {
            swap(arr[2 * i], arr[2 * i + 1]);
        }
        ll s1 = 0, s2 = 0;
        for1(i, n-1) {
            s1 += abs(arr[i-1] - arr[i]);
            s2 += arr[i-1] - arr[i];
        }
        assert(s1 - abs(s2) == 2 * k);

        for (auto it : arr) cout << it << ' ';
        cout << '\n';
    }
    return 0;
}

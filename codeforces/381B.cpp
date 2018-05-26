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

    int N;
    while (cin >> N) {
        vector<int> arr(N);
        forn(i, N) cin >> arr[i];
        sort(all(arr));

        vector<int> ans;
        vector<int> used(N, false);
        forn(i, N) {
            if (i == 0 || (!used[i] && ans.back() < arr[i])) {
                used[i] = true;
                ans.push_back(arr[i]);
            }
        }
        ford(i, N) {
            if (!used[i] && ans.back() > arr[i]) {
                used[i] = true;
                ans.push_back(arr[i]);
            }
        }

        cout << sz(ans) << '\n';
        for (auto it : ans) cout << it << ' ';
        cout << '\n';
    }
    return 0;
}

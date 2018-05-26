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
        vector<int> arr(M);
        forn(i, M) cin >> arr[i];
        sort(all(arr));
        bool ok = true;
        forn(i, M-2)  {
            if (arr[i]+1 == arr[i+1] && arr[i+1]+1 == arr[i+2])
                ok = false;
        }
        if (find(all(arr), 1) != arr.end() || find(all(arr), N) != arr.end() || !ok) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}

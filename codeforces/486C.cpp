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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int N, P;
    string S;
    while (cin >> N >> P >> S) {
        int mid = (N+1) / 2;
        if (P > mid) {
            forn(i, N/2) swap(S[i], S[N-i-1]);
            P = N - P + 1;
        }
        int r = -1, l = -1;
        ford(i, N/2) {
            if (P-1 > i) break;
            if (S[i] != S[N-i-1]) {
                r = i;
                break;
            }
        }
        forn(i, P) {
            if (S[i] != S[N-i-1]) {
                l = i;
                break;
            }
        }
        if (l == -1 && r == -1) {
            cout << 0 << '\n';
            continue;
        }
        --P;
        if (l == -1) l = P;
        else if (r == -1) r = P;

        int res = min(abs(l - P), abs(r - P));
        fore(i, l, r) {
            vector<char> c {S[i], S[N-i-1]};
            sort(all(c));
            int diff = min(abs(c[0] - c[1]), abs(c[0] + 26 - c[1]));
            res += diff;
        }
        cout << res + (r - l) << '\n';
    }
    return 0;
}

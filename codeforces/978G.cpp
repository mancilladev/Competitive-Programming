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

    int n, m;
    while (cin >> n >> m) {
        vector<int> day(n), who(n), cnt(n);
        vector<pii> g[n];
        forn(i, m) {
            int s, d, c; cin >> s >> d >> c;
            --s, --d;
            day[d] = 1;
            who[d] = i;
            cnt[i] = c;
            g[s].push_back({d, i});
        }

        vector<int> res;
        priority_queue<pii, vector<pii>, greater<pii>> q;
        forn(i, n) {
            for (auto p : g[i]) q.push(p);
            if (day[i]) {
                if (cnt[who[i]] != 0) {
                    res.clear();
                    break;
                }
                res.push_back(m + 1);
                continue;
            }

            if (q.empty()) res.push_back(0);
            else {
                int idx = q.top().se;
                res.push_back(idx + 1);
                --cnt[idx];
                if (cnt[idx] == 0) q.pop();
            }
        }

        if (sz(res) == n) {
            forn(i, n) cout << res[i] << ' ';
            cout << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
}

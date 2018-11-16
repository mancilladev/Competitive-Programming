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

struct DSU
{
    map<pii,pii> parent;
    void make_set (pii p) {
        parent[p] = p;
    }
    pii find_set (pii p) {
        if (parent[p] == p) return p;
        return parent[p] = find_set(parent[p]);
    }
    void union_set (pii a, pii b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            parent[b] = a;
        }
    }
};

int main (void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    while (cin >> n) {
        DSU dsu = DSU();
        vector<pii> arr;
        forn(i, n) {
            int x, y; cin >> x >> y;
            pii p = {x, y};
            dsu.make_set(p);
            for (auto q : arr) {
                if (q.fi == p.fi || q.se == p.se) {
                    dsu.union_set(p, q);
                }
            }
            arr.push_back(p);
        }
        int ans = 0;
        for (auto p : arr) if (dsu.find_set(p) == p) ++ans;
        cout << ans - 1 << '\n';
    }
    return 0;
}

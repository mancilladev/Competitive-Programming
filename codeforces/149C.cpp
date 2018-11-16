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

struct Team
{
    int n = 0;
    ll sum = 0;
    vector<int> v;
    void add (int idx, int val) {
        v.push_back(idx);
        sum += val;
        ++n;
    }
};

int main (void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    while (cin >> n) {
        vector<pii> arr(n);
        forn(i, n) {
            cin >> arr[i].fi;
            arr[i].se = i+1;
        }
        sort(all(arr), greater<pii>());

        Team t[2] = {{}};
        forn(i, n) {
            t[i&1].add(arr[i].se, arr[i].fi);
        }
        forn(i, 2) {
            cout << t[i].n << '\n';
            for (auto it : t[i].v) cout << it << ' ';
            cout <<'\n';
        }
    }
    return 0;
}

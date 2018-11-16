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
typedef long double ld;
typedef pair<int,int> pii;

const int MN = 2e5 + 7;

struct Red
{
    ld sum = 0;
    vector<ld> v {0};
    vector<ll> upd;
    Red () {
        upd.resize(MN);
    }
    void push (int x) {
        v.push_back(x);
        sum += x;
    }
    void pop () {
        int k = sz(v);
        upd[k-1] += upd[k];
        sum -= (v.back() + upd[k]);
        v.pop_back();
        upd[k] = 0;
    }
    void add (int a, int x) {
        sum += 1LL * a * x;
        upd[a] += x;
    }
    double avg () {
        return sum / sz(v);
    }
};

int main (void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    while (cin >> n) {
        Red red = Red();
        vector<int> arr;
        forn(i, n) {
            int t; cin >> t;
            if (t == 1) {
                int a, x; cin >> a >> x;
                red.add(a, x);
            }
            else if (t == 2) {
                int k; cin >> k;
                red.push(k);
            }
            else {
                red.pop();
            }
            cout << red.avg() << '\n';
        }
    }
    return 0;
}

#include <bits/stdc++.h>
#define PB push_back
#define sq(x) ((x) * (x))
using namespace std;
typedef long long ll;
typedef long double ld;

struct Node {
    ll x;
    ll y;
} a, b, c;

ll dist(auto p, auto q) {
    // don't use sqrt for precision
    return sq(p.x-q.x) + sq(p.y-q.y);
}

int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;
    ll d1 = dist(a, b);
    ll d2 = dist(b, c);
    // first check non collinearity
    if ((b.y - a.y)*(c.x - b.x) == (c.y - b.y)*(b.x - a.x))
        cout << "No\n";
    else if (d1 == d2)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}

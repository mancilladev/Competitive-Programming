#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

struct Node {
    ld x;
    ld y;
} a, b, c;

ld dist(auto p, auto q) {
    return sqrt((p.x-q.x)*(p.x-q.x) + (p.y-q.y)*(p.y-q.y));
}

int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;
    ld d1 = dist(a, b);
    ld d2 = dist(b, c);
    ld d3 = dist(c, a);
    printf("%LF %LF %LF", d1, d2, d3);
    if (d1 == d2 || d2 == d3)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}

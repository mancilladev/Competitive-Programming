#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
ld r;

struct Point {
    ld x;
    ld y;
} p1, p2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> r;
    cin >> p1.x >> p1.y;
    cin >> p2.x >> p2.y;
    ld d = sqrt(pow(p1.x-p2.x, 2) + pow(p1.y-p2.y, 2));
    cout << ceil(d/(2.0*r)) << '\n';

    return 0;
}

#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

int t, sx, sy, ex, ey;
unordered_map<char, pair<int, int> > d {{'E', {1,0}}, {'S', {0,-1}}, {'N', {0,1}}, {'W', {-1,0}}};
int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> t >> sx >> sy >> ex >> ey;
    for (int i = 0; i < t; ++i) {
        char c; cin >> c;
        int x, y;
        tie(x, y) = d[c];

        int next_x = sx + x;
        int next_y = sy + y;
        if ((abs(ex - next_x) + abs(ey - next_y)) < (abs(ex - sx) + abs(ey - sy)))
            sx = next_x, sy = next_y;

        if (sx == ex && sy == ey)
            return cout << (i+1) << endl, 0;
    }
    cout << -1 << endl;
    return 0;
}

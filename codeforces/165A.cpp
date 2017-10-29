#include <bits/stdc++.h>
#define PB push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

struct Node {
    int x;
    int y;
} ;

int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    int n; cin >> n;
    vector<Node> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i].x >> a[i].y;
    int ans = 0;
    for (auto p : a) {
        vector<int> has(5, 0);
        for (auto q : a) {
            if (q.x > p.x && q.y == p.y)
                has[0] = 1;
            else if (q.x < p.x && q.y == p.y)
                has[1] = 1;
            else if (q.x == p.x && q.y < p.y)
                has[2] = 1;
            else if (q.x == p.x && q.y > p.y)
                has[3] = 1;
        }
        int val = 0;
        for (int i = 0; i < 4; ++i)
            val += has[i];
        if (val == 4)
            ++ans;
    }
    cout << ans << '\n';
    return 0;
}

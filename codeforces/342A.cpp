#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

int N, cnt[10];
int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> N;
    for (int i = 0, x; i < N; ++i) {
        cin >> x;
        cnt[x]++;
    }

    vector<vector<int> > res;
    for (int i = 0; i < N/3; ++i) {
        vector<int> l;
        for (int x : {1,2,3,4,6}) if (cnt[x]) {
            if ((int)l.size() && x%l.back()) continue;
            --cnt[x];
            l.PB(x);
            if ((int)l.size() == 3) break;
        }
        if ((int)l.size() != 3) break;
        res.PB(l);
    }

    if ((int)res.size() != N/3) cout << -1 << endl;
    else for (auto l : res) cout << l[0] << ' ' << l[1] << ' ' << l[2] << '\n';

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define error(x) cerr << #x << " = " << x << endl;
#define mt make_tuple
#define eb emplace_back
#define pb push_back
typedef long long ll;
typedef long double ld;

int N;
int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> N;
    vector<int> diff(N+1);
    unordered_map<int, int> pos;

    diff[0] = 0;
    pos[0] = 0;
    int res = 0;
    for (int i = 1; i <= N; ++i) {
        char c; cin >> c;
        diff[i] = diff[i-1] + (c == '1' ? 1 : -1);
        if (pos.find(diff[i]) == pos.end())
            pos[diff[i]] = i;
        else
            res = max(res, i - pos[diff[i]]);
    }

    cout << res << endl;
    return 0;
}

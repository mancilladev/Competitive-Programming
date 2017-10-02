#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

const int MAX = 1e5 + 7;
int N, last[MAX], num[MAX], dist[MAX];
bool w[MAX];
int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    int a, ans = 0;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> a;
        num[a]++;
        if (last[a]) {
            if (num[a] == 2) dist[a] = i - last[a];
            if (i - dist[a] != last[a]) w[a] = true;
        }
        last[a] = i;
    }
    for (int i = 1; i < MAX; ++i) if (num[i] && !w[i]) ++ans;
    cout << ans << '\n';
    for (int i = 1; i < MAX; ++i) if (num[i] && !w[i]) cout << i << ' ' << dist[i] << '\n';
    return 0;
}

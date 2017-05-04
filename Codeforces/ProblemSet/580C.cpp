#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
const int MAX = (1e5);
int N, M, arr[MAX] {0};
vector<int> h[110000];

int dfs(int parent, int child) {
    if (arr[child] > M)
        return 0;
    if (h[child].size() == 1 && child != 1)
        return 1;
    int res = 0;
    for (int y: h[child]) {
        if (y == parent)
            continue;
        if (arr[child] > arr[parent] && arr[y])
            arr[y] += arr[child];
        res += dfs(child, y);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
        cin >> arr[i];
    for (int i = 0; i < N-1; ++i) {
        int x, y; cin >> x >> y;
        h[x].PB(y);
        h[y].PB(x);
    }

    cout << dfs(0, 1) << '\n';

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
ll T, N, M;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> N >> M;
    vector<vector<int> > arr(N, vector<int>(2*M));
    int res = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            bool a, b;
            cin >> a >> b;
            if (a || b)
                ++res;
        }
    }
    cout << res << '\n';

    return 0;
}

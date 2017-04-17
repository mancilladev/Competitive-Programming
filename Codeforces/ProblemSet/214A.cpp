#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
int N, M;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> N >> M;
    int T = max(N, M);
    int res = 0;
    for (int a = 0; a <= T; ++a)
        for (int b = 0; b <= T; ++b) {
            if (a * a + b == N && a + b * b == M) ++res;
        }
    cout << res << '\n';

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
const int MAX = 101;
int N, K, arr[MAX][MAX] {0};

bool solvable() {
    if (K > N*N || (K > N && (K-N)%2 != 0))
        return false;
    for (int i = 0; i < N && K--; ++i)
        arr[i][i] = 1;
    for (int t = 1; t < N && K > 0; ++t) {
        for (int i = 0; i < t && K && !arr[i][t-i]; ++i) {
            arr[i][t-i] = 1;
            arr[t-i][i] = 1;
            K -= 2;
        }
    }
    for (int t = N-1; t > 0 && K > 0; --t) {
        for (int i = 0; i < t && K && !arr[N-i-1][N-t-1]; ++i) {
            arr[N-i-1][N-t-1] = 1;
            arr[N-t-1][N-i-1] = 1;
            K -= 2;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> N >> K;

    if (solvable()) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j)
                cout << arr[i][j] << ' ';
            cout << '\n';
        }
    } else
        cout << -1 << '\n';

    return 0;
}

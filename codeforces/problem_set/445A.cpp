#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

int N, M;
char arr[107][107];
int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i <= N; ++i) {
        char cur = (i&1 ? 'W' : 'B');
        for (int j = 1; j <= M; ++j) {
            if (arr[i][j] != '-')
                arr[i][j] = cur;
            cur = (cur == 'W' ? 'B' : 'W');
            cout << arr[i][j];
        }
        cout << '\n';
    }
    return 0;
}

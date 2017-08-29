#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
int N, res = 0;
char arr[1002][1002];

bool clear(int y, int x) {
    if (y > 0 && arr[y-1][x] == 'C')
        return false;
    if (arr[y+1][x] == 'C')
        return false;
    if (x > 0 && arr[y][x-1] == 'C')
        return false;
    if (arr[y][x+1] == 'C')
        return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> N;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            if (clear(y, x))
                arr[y][x] = 'C', ++res;
            else
                arr[y][x] = '.';
        }
    }

    cout << res << '\n';
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x)
            cout << arr[y][x];
        cout << '\n';
    }

    return 0;
}

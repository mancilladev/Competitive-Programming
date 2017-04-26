#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
int N, arr[101][101];

bool good(int pos) {
    for (int i = 0; i < N; ++i)
        if (arr[pos][i] == 1 || arr[pos][i] == 3)
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> arr[i][j];

    vector<int> cars;
    for (int i = 0; i < N; ++i)
        if (good(i)) cars.PB(i);

    cout << cars.size() << '\n';
    for (int x: cars)
        cout << x+1 << ' ';
    if (cars.size())
        cout << '\n';

    return 0;
}

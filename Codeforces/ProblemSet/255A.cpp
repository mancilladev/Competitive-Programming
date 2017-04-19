#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
ll N, M;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> N;
    vector<ll> arr(3, 0);
    int cur;
    for (int i = 0; i < N; ++i)
        cin >> cur, arr[i%3] += cur;

    int _max = max(arr[0], max(arr[1], arr[2]));
    if (arr[0] == _max)
        cout << "chest" << endl;
    else if (arr[1] == _max)
        cout << "biceps" << endl;
    else if (arr[2] == _max)
        cout << "back" << endl;

    return 0;
}

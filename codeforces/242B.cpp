#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

int N;
int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> N;
    vector<pair<int,int> > arr(N);
    int mini = 1e9+7, maxi = 0;
    for (int i = 0, a, b; i < N; ++i) {
        cin >> a >> b;
        mini = min(mini, a);
        maxi = max(maxi, b);
        arr[i] = {a, b};
    }
    for (int i = 0; i < N; ++i)
        if (arr[i].first == mini && arr[i].second == maxi)
            return cout << i+1 << '\n', 0;
    cout << -1 << '\n';
    return 0;
}

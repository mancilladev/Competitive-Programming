#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

int N;
int main(void) {
# ifdef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
# endif
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> N; N *= 2;
    vector<pair<int, int> > arr(N);
    for (int i = 0, x; i < N; ++i) {
        cin >> x;
        arr[i] = {x, i+1};
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < N; i += 2)
        if (arr[i].first != arr[i+1].first)
            return cout << -1 << endl, 0;
    for (int i = 0; i < N; i += 2)
        cout << arr[i].second << ' ' << arr[i+1].second << '\n';
    return 0;
}

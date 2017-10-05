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
    int sum = 0;
    for (int i = 0, x; i < N; ++i) {
        cin >> x;
        sum += x;
    }
    if (sum % N == 0)
        cout << N << '\n';
    else
        cout << N-1 << '\n';
    return 0;
}

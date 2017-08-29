#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);

const int N = (int)3e5 + 7;
unsigned int a[N];
int n, m;

int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    const int M = *max_element(a, a+n) + 100;
    unsigned int x;
    while (m--) {
        cin >> x;
        int b[M] {0};
        for (int i = 0; i < n; ++i) {
            a[i] = a[i] xor x;
            b[a[i]]++;
        }
        int i = 0;
        for (; i < N; ++i) if (b[i] == 0)
            break;
        cout << i << '\n';
    }
    return 0;
}

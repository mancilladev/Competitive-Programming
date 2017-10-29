#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

int n, m, a[100], b[100];
map<int, int> H;
int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; ++i)
        cin >> b[i];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            float x = b[j]*1.0/a[i];
            if ((int)x == x)
                H[(int)x]++;
        }
    cout << H.rbegin()->second << endl;
    return 0;
}

#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

int n, a[7];

int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < 7; ++i)
        cin >> a[i];
    int day = 6;
    while (n > 0) {
        day = (day + 1)%7;
        n -= a[day];
    }
    cout << day + 1 << endl;
    return 0;
}

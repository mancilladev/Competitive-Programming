#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

int N, a[107], b[107];
int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> N;
    char c;
    for (int i = 0; i < N; ++i) { cin >> c; a[i] = c - '0'; }
    for (int i = 0; i < N; ++i) { cin >> c; b[i] = c - '0'; }
    sort(a, a+N);
    sort(b, b+N);
    int less = 1;
    for (int i = 0; i < N; ++i) if (a[i] >= b[i]) less = 0;
    int more = 1;
    for (int i = 0; i < N; ++i) if (a[i] <= b[i]) more = 0;
    if (less || more)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}

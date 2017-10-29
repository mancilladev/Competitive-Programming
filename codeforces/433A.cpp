#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

int N, t[5];
int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> N;
    set<int> st;
    for (int i = 0, x; i < N; ++i) {
        cin >> x;
        t[x/100]++;
    }
    if ((t[2]&1 && t[1]>1 && t[1]&1^1) || (t[2]&1^1 && t[1]&1^1))
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}

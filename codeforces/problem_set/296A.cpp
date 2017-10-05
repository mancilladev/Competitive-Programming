#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

int N, cnt[1007];
int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> N;
    for (int i = 0, x; i < N; ++i) {
        cin >> x;
        cnt[x]++;
    }
    int mode = *max_element(cnt, cnt+1007);
    if ((N+1)/2 >= mode)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}

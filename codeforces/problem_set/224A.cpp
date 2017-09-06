#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

ld s1, s2, s3;
int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> s1 >> s2 >> s3;
    int a = sqrt(s1*s2/s3);
    int b = sqrt(s1*s3/s2);
    int c = sqrt(s2*s3/s1);
    int ans = a + b + c;
    cout << ans * 4 << '\n';
    return 0;
}

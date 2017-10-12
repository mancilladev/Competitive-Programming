#include <bits/stdc++.h>
using namespace std;
#define error(x) cerr << #x << " = " << x << endl;
#define mt make_tuple
#define eb emplace_back
#define pb push_back
typedef long long ll;
typedef long double ld;

int Y, W;
int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> Y >> W;
    int a = 6 - max(Y, W) + 1;
    int g = __gcd(a, 6);
    cout << a/g << '/' << 6/g << endl;
    return 0;
}

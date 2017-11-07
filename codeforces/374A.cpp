#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

#define FOR(i, a, b) for (int i = a, b_ = b; i < b_; ++i)
#define REP(i, n) FOR(i, 0, n)
#define pb push_pack
#define mp make_pair
#define f first
#define s second
#define endl '\n'

const int INF = 1e9+7;
int n, m, i, j, a, b;

int check(int x, int y) {
    int d1 = abs(x - i);
    int d2 = abs(y - j);
    if (d1%a != 0 || d2%b != 0) return INF;
    if (((d1/a)&1) != ((d2/b)&1)) return INF;
    return max(d1/a, d2/b);
}

int main(void) {
    cin >> n >> m >> i >> j >> a >> b;
    int res = INF;
    res = min(res, check(n, 1));
    res = min(res, check(1, m));
    res = min(res, check(1, 1));
    res = min(res, check(n, m));
    if (res == INF) cout << "Poor Inna and pony!\n";
    else cout << res << endl;
	return 0;
}

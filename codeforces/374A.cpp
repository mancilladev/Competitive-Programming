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
    if (x == i && y == j) return 0;
    
    if (i - a < 1 && i + a > n) return INF;
    if (j - b < 1 && j + b > m) return INF;
    if (abs(x - i) % a) return INF;
    if (abs(y - j) % b) return INF;
    
    int cost = max(abs(x - i) / a, abs(y - j) / b);
    int tmp = abs(x - i) / a + abs(y - j) / b;
    if (tmp&1) return INF;
    return cost;
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

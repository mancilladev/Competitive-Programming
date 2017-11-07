#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

#define FOR(i, a, b) for (int i(a), b_ = b; i < b_; ++i)
#define REP(i, n) FOR(i, 0, n)
#define pb push_back
#define mp make_pair
#define sq(x) (x) * (x)
#define endl '\n'
#define f first
#define s second

vector<pii> coord(3);

int dist(int a, int b) {
	return sq(coord[a].f - coord[b].f) + sq(coord[a].s - coord[b].s);
}

bool solve() {
	int ab = dist(0, 1);
	int bc = dist(1, 2);
	int ca = dist(2, 0);
	if (ab*bc*ca == 0) return false;
	return (ab + bc == ca || ab + ca == bc || bc + ca == ab);
}

int main(void) {
	REP(i, 3) cin >> coord[i].f >> coord[i].s;
	if (solve()) return cout << "RIGHT\n", 0;
	REP(i, 3) {
		FOR(x, -1, 2) FOR(y, -1, 2) {
			if (x != 0 && y != 0) continue;
			coord[i].f += x;
			coord[i].s += y;
			if (solve()) return cout << "ALMOST\n", 0;
			coord[i].f -= x;
			coord[i].s -= y;
		}
	}
	cout << "NEITHER\n";
	return 0;
}

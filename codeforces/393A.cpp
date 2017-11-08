#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = (int)1e9 + 7;

#define FOR(i, a, b) for (int i = a, b_ = b; i < b_; ++i)
#define REP(i, n) FOR(i, 0, n)
#define FORD(i, a, b) for (int i = a, b_ = b; i >= b; --i)
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl '\n'

string nineteen = "nineteen";
int n;

int main(void) {
    string u = nineteen;
    sort(all(u)), u.erase(unique(all(u)), u.end());
    
    string st; cin >> st;
    int res = INF;
    for (auto c : u) {
        int nes = count(all(nineteen), c);
        int cur = count(all(st), c);
        if (c == 'n') {
            nes--;
            res = min(res, (cur-1) / nes);
        } else {
            res = min(res, cur / nes);
        }
    }
    cout << res << endl;
	return 0;
}

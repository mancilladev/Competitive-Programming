#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = (int)1e9 + 7;
#define deb(x) cerr << #x << " = " << x << endl
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define sq(x) (x) * (x)
#define fi first
#define se second
#define UNIQUE(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define FOR(i, a, b) for (int i(a); i < b; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a); i >= b; --i)

const int MN = 2e5 + 7;
int N;

struct Lap {
    int id;
    double speed, ram, hdd, cost;
    bool outdatedBy (Lap& other) {
        return speed < other.speed && ram < other.ram && hdd < other.hdd;
    }
};

bool cmp(Lap l1, Lap l2) {
    return l1.cost < l2.cost;
}

int main (void) {
    while (cin >> N) {
        vector<Lap> a(N), b;
        REP(i, N) {
            a[i].id = i+1;
            cin >> a[i].speed >> a[i].ram >> a[i].hdd >> a[i].cost;
        }
        for (auto l1 : a) {
            bool flag = false;
            for (auto l2 : a) flag |= l1.outdatedBy(l2);
            if (!flag) b.push_back(l1);
        }
        sort(all(b), cmp);
        cout << b[0].id << '\n';
    }
    return 0;
}

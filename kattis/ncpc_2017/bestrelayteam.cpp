#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = (int)1e9 + 7;
#define deb(x) cerr << #x << " = " << x << endl
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define sq(x) (x) * (x)
#define pb push_back
#define fi first
#define se second
#define endl '\n'
#define UNIQUE(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define FOR(i, a, b) for (int i(a); i < b; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a); i >= b; --i)

const int N = 500 + 7;
int n, res;

struct Node {
    string name;
    ld fi;
    ld se;
    bool operator <(const Node& other) {
        return se < other.se;
    }
} team[N];

ld createTeam(int x) {
    ld time = team[x].fi;
    int missing = 3;
    REP(i, n && missing) {
        if (i == x) continue;
        time += team[i].se;
        --missing;
    }
    return time;
}

void printAns() {
    cout << fixed << setprecision(numeric_limits<double>::max_digits10) << createTeam(res) << endl;
    cout << team[res].name << endl;
    int missing = 3;
    REP(i, n && missing) {
        if (i == res) continue;
        cout << team[i].name << endl;
        --missing;
    }
}

int main(void) {
    cin >> n;
    REP(i, n)
        cin >> team[i].name >> team[i].fi >> team[i].se;
    sort(team, team + n);
    REP(i, n) {
        if (createTeam(i) < createTeam(res))
            res = i;
    }
    printAns();
    return 0;
}

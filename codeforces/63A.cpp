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
#define FOR(i, a, b) for (int i(a); i < b; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a); i >= b; --i)

const int MN = 2e5 + 7;
int N;

map<string, int> status {
    {"rat", 0},
    {"woman", 1},
    {"child", 1},
    {"man", 2},
    {"captain", 3}
};

struct Node {
    int id;
    string name;
    string status;
};

bool cmp (Node& a, Node& b) {
    if (a.status == b.status)
        return a.id < b.id;
    return a.status < b.status;
}

int main (void) {
    while (cin >> N) {
        vector<Node> a(N);
        REP(i, N) {
            string key;
            cin >> a[i].name >> key;
            a[i].id = i;
            a[i].status = status[key];
        }
        sort(all(a), cmp);
        for (auto node : a)
            cout << node.name << '\n';
    }
    return 0;
}

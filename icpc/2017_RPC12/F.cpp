#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
template <class T> using min_queue = priority_queue<T, vector<T>, greater<T>>;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int INF = (int)1e9 + 7;
const long long LLINF = (ll)4e18 + 7;
const double pi = acos(-1.0);

#define deb(x) cerr << #x << " = " << x << endl
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define sq(x) (x) * (x)
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl '\n'

#define UNIQUE(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define FOR(i, a, b) for (int i(a), b_(b); i < b_; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a), b_(b); i >= b_; --i)

const int N = 57;
int n, z, T, be, en;
int dist[N], parent[N], processed[N];
vector<vector<pii>> e;

void dijkstra(int x) {
    dist[x] = 0;
    min_queue<pii> q;
    q.push({0, x});
    while (!q.empty()) {
        int a = q.top().s; q.pop();
        if (processed[a]) continue;
        processed[a] = 1;
        for (auto u : e[a]) {
            int b = u.f, w = u.s;
            if (dist[a]+w < dist[b]) {
                dist[b] = dist[a]+w;
                parent[b] = a;
                q.push({dist[b], b});
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> T;
    REP(t, T) {
        cin >> n >> z;
        // edge list
        e.clear(); e.resize(n);
        cin.ignore();
        REP(i, n) {
            string st;
            getline(cin, st);
            istringstream iss(st);

            int a, b, w;
            iss >> a;
            while (iss >> b >> w) e[a].eb(b, w);
        }

        // dists, processed and parent
        REP(i, n) {
            dist[i] = INF;
            processed[i] = 0;
            parent[i] = i;
        }

        // teleporters
        vector<int> arr;
        REP(i, 2*z) {
            int x; cin >> x;
            arr.pb(x);
        }
        REP(i, 2*z-1) {
            e[arr[i]].eb(arr[i+1], 0);
            e[arr[i+1]].eb(arr[i], 0);
        }

        // query
        cin >> be >> en;
        dijkstra(be);

        // answer
        if (dist[en] == INF) {
            cout << "Case #" << t+1 << ": " << "Path does not exist\n";
        } else {
            cout << "Case #" << t+1 << ": " << dist[en] << endl;

            vector<int> path;
            while(en != be) path.pb(en), en = parent[en];
            path.pb(be);
            reverse(all(path));
            REP(i, sz(path)) {
                if (i) cout << ' ';
                cout << path[i];
            }
            cout << endl;
        }
    }
    return 0;
}

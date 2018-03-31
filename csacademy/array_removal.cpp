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

template < typename I >
ostream& operator <<( ostream& os, const vector< I > & v) {
    os << '{';
    for (auto it = begin(v); it != end(v); ++it) {
        if (it != begin(v))
            os << ", ";
        os << *it;
    }
    return os << '}';
}

const int INF = (int)1e9 + 7;
const long long LLINF = (ll)4e18 + 7;
const double pi = acos(-1.0);

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

const int Z = 1e5 + 7;
int n;
vector<int> parent, tam;
vector<ll> sum;

// DSU

void make_set(int v, int w) {
    parent[v] = v;
    tam[v] = 1;
    sum[v] = w;
}

int find_set(int v) {
    if (parent[v] == v)
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (tam[a] < tam[b])
            swap(a, b);
        parent[b] = a;
        tam[a] += tam[b];
        sum[a] += sum[b];
    }
}

int main (void) {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> n;
    parent.resize(n, -1);
    tam.resize(n);
    sum.resize(n);

    vector<int> a(n), op(n);
    for (auto& x : a)
        cin >> x;
    for (auto& x: op) {
        cin >> x;
        --x;
    }

    reverse(all(op));
    deque<ll> res;
    ll best = 0;
    for (auto x: op) {
        make_set(x, a[x]);
        if (x - 1 >= 0 && parent[x-1] != -1)
            union_sets(x, x-1);
        if (x + 1 < n && parent[x+1] != -1)
            union_sets(x, x+1);
        best = max(best, sum[find_set(x)]);
        res.push_front(best);
    }

    for (auto x : res)
        cout << x << '\n';

    return 0;
}

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<int,int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define error(x) cerr << #x << " = " << x << endl
#define CL(a, v) memset(a, v, sizeof a)
#define sz(x) (int)(x).size()
#define sq(x) (x) * (x)
#define eb emplace_back
#define pb push_back
#define f first
#define s second
#define endl '\n'

template <class T, class M = T>
class SegmentTreeR {
    int n, height;
    vector<T> _tree;
    vector<M> delta;

    void calc(int i, int k) {
        _tree[i] = combine(_tree[i<<1], _tree[i<<1|1]);
        if (delta[i]) _tree[i].add(delta[i], k);
    }

    void apply(int i, const M& value, int k) {
        _tree[i].add(value, k);
        if (i < n) delta[i].add(value);
    }
public:
    SegmentTreeR(int newn = 0) { init(newn); }

    void init(int newn) {
        n = newn;
        height = sizeof(n) * 8 - __builtin_clz(n);
        vector<T>(2*n).swap(_tree);
        vector<M>(n, M(false)).swap(delta);
    }

    int size() const { return n; }
    T& operator [] (int i) { return _tree[i + n]; }
    const T& operator [] (int i) const { return _tree[i + n]; }

    void build(int l, int r) {
        int k = 2;
        for (l += n, r += n-1; r >>= 1, l >>= 1; k <<= 1) {
            for (int i = r; i >= l; --i) calc(i, k);
        }
    }
    void build() { build(0, n); }

    void push(int l, int r) {
        int h = height, k = 1 << (h-1);
        for (l += n, r += n-1; h; --h, k >>= 1) {
            for (int i = l >> h; i <= r >> h; ++i) if (delta[i]) {
                apply(i<<1, delta[i], k);
                apply(i<<1|1, delta[i], k);
                delta[i] = M(false);
            }
        }
    }
    void push() { push(0, n); }

    void modify(int l, int r, const M& value) {
        if (!value) return;
        push(l, l + 1);
        push(r - 1, r);
        bool cl = false, cr = false;
        int k = 1;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1, k <<= 1) {
            if (cl) calc(l - 1, k);
            if (l&1) apply(l++, value, k), cl = true;
            if (cr) calc(r, k);
            if (r&1) apply(--r, value, k), cr = true;
        }
        for (--l; r; l >>= 1, r >>= 1, k <<= 1) {
            if (cl) calc(l, k);
            if (cr && (!cl || l != r)) calc(r, k);
        }
    }

    T query(int l, int r) {
        push(l, l + 1);
        push(r - 1, r);
        T resl = T(), resr = T();
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) resl = combine(resl, _tree[l++]);
            if (r&1) resr = combine(_tree[--r], resr);
        }
        return combine(resl, resr);
    }
};

struct M {
    int color;

    M(int color) : color(color) {}
    explicit M(bool) : color(-1) {}
    explicit operator bool () const { return color != -1; }

    void add(const M& other) { color = other.color; }
};

const int C = 60;
struct F {
    int count[C];

    void add(const M& delta, int k = 1) {
        CL(count, 0);
        count[delta.color] = k;
    }

    friend F combine(const F& a, const F& b) {
        F res;
        for (int i = 0; i < C; ++i) res.count[i] = a.count[i] + b.count[i];
        return res;
    }
};

const int INF = 1e9 + 7, N = 4e5 + 5;
int n, m, c[N];
vector<int> e[N];
SegmentTreeR<F, M> seg;

int tin[N], tout[N], tt = 0;

void dfs(int v, int p) {
  tin[v] = tt++;
  for (int u : e[v]) if (u != p) dfs(u, v);
  tout[v] = tt;
}

int main(void) {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        c[i] = x;
    }
    for (int i = 0; i < n-1; ++i) {
        int x, y; cin >> x >> y;
        --x; --y;
        e[x].pb(y);
        e[y].pb(x);
    }

    dfs(0, -1);
    seg.init(n);
    for (int i = 0; i < n; ++i) seg[tin[i]].add(c[i]-1);
    seg.build();

    for (int i = 0; i < m; ++i) {
        int t, v, c; cin >> t >> v;
        --v;
        if (t == 1) {
            cin >> c;
            seg.modify(tin[v], tout[v], c-1);
        } else {
            F res = seg.query(tin[v], tout[v]);
            int k = 0;
            for (int j = 0; j < C; ++j) if (res.count[j] > 0) ++k;
            cout << k << endl;
        }
    }

#ifdef LOCAL
    cout << endl << endl << static_cast<double>(clock()) / CLOCKS_PER_SEC << endl;
#endif
    return 0;
}

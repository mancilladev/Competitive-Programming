#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

const int N = 1e6 + 7;
int tx, ty, n, x[N], y[N], h[N];
map<pii,vector<int>> m;

int longest(vector<int>& v) {
    multiset<int> st;
    for (auto x : v) {
        st.insert(x);
        auto it = st.find(x); ++it;
        if (it != st.end()) st.erase(it);
    }
    for (auto x : st) cout << x << ' ';
    cout << endl;
    return (int)st.size();
}

void normalize(int i) {
    int a = (x[i] - tx);
    int b = (y[i] - ty);
    int g = __gcd(a, b);
    m[make_pair(a/g, b/g)].push_back(h[i]);
}

int main(void) {
    cin >> tx >> ty >> n;
    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i] >> h[i], normalize(i);
    int res  = 0;
    for (auto& t : m) {
        cout << "{" << t.first.first << "," << t.first.second << "} : ";
        for (auto& x : t.second) cout << x << ' ';
        cout << endl;
        res += longest(t.second);
    }
    cout << res << endl;
    return 0;
}

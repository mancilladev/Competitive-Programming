#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

const int N = 1e6 + 7;
int tx, ty, n, x[N], y[N], h[N];
map<pii,vector<int>> m;

int longest(vector<int>& v) {
    set<int> st;
    for (auto x : v) {
        if (st.find(x) != st.end()) continue;
        st.insert(x);
        auto it = st.find(x); ++it;
        if (it != st.end()) st.erase(it);
    }
    return (int)st.size();
}

void normalize(int i) {
    int a = (x[i] - tx);
    int b = (y[i] - ty);
    int g = __gcd(abs(a), abs(b));
    m[make_pair(a, b)].push_back(h[i]);
}

int main(void) {
    cin >> tx >> ty >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i] >> h[i];
        normalize(i);
    }
    int res  = 0;
    for (auto& t : m) {
        res += longest(t.second);
    }
    cout << res << endl;
    return 0;
}

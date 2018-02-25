#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

const int INF = 1e9, N = 10000;
int n, m, out[N];
pii s[N];
pair<int,pii> b[N]; // cost, capacity, num

int main(void) {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> s[i].first, s[i].second = i;
    for (int i = 0; i < m; ++i) {
        cin >> b[i].second.first;
        b[i].second.second = i;
    }
    for (int i = 0; i < m; ++i) cin >> b[i].first;
    sort(s, s + n);
    sort(b, b + m);
    for (int i = 0; i < m; ++i) for (int j = n-1; j >= 0; --j) {
        if (b[i].second.first >= s[j].first && out[s[j].second] == 0) {
            out[s[j].second] = b[i].second.second + 1;
            break;
        }
    }
    for (int i = 0; i < n; ++i) if (out[i] == 0) return cout << "impossible\n", 0;
    for (int i = 0; i < n; ++i) cout << out[i] << " ";
    cout << endl;
    return 0;
}

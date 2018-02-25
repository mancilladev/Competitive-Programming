#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define sz(a) (int)a.size()

int main(void) {
    string s; cin >> s;
    deque<pii> res;
    for (int i = 0; i < sz(s); ++i) {
        int p = -1;
        for (int j = i + 1; j < sz(s); ++j) {
            if (s[j] < s[i] && (p == -1 || s[j] < s[p])) p = j;
        }
        if (p != -1) {
            swap(s[i], s[p]);
            res.push_front({p+1, i+1});
        }
    }
    for (auto& p : res) cout << p.first << ' ' << p.second << '\n';
    return 0;
}

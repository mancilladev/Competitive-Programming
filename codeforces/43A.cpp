#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

int n;
unordered_map<string, int> m;
int main(void) {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        m[s]++;
    }
    string res = "";
    int maxi = 0;
    for (auto p : m) {
        if (p.second > maxi) {
            res = p.first;
            maxi = p.second;
        }
    }
    cout << res << endl;
    return 0;
}

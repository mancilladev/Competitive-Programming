#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
string s;

string result() {
    string ans = s;
    int last = s.size()-1;
    for (int i = 0; i <= last; ++i) {
        if ((s[i] - '0')%2 == 0 && s[i] < s[last]) {
            ans[i] = s[last], ans[last] = s[i];
            return ans;
        }
    }
    for (int i = last; i >= 0; --i) {
        if ((s[i] - '0')%2 == 0 && s[i] > s[last]) {
            ans[i] = s[last], ans[last] = s[i];
            return ans;
        }
    }
    return "-1";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> s;
    cout << result() << '\n';

    return 0;
}

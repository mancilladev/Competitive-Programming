#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
int N, D;
string s;

bool allPresent() {
    for (char c: s)
        if (c != '1')
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> N >> D;
    int res = 0;
    int cur = 0;
    for (int i = 0; i < D; ++i) {
        cin >> s;
        if (allPresent())
            cur = 0;
        else
            ++cur;
        res = max(res, cur);
    }
    cout << res << '\n';

    return 0;
}

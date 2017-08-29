#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
const ll INF = ll(1e18);
vector<int> ab, ba;

bool solves() {
    for (auto x: ab)
        for (auto y: ba)
            if (abs(x - y) > 1)
                return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    string str;
    cin >> str;
    for (int i = 1; i < str.size(); ++i) {
        if (str[i-1] == 'A' && str[i] == 'B')
            ab.PB(i-1);
        if (str[i-1] == 'B' && str[i] == 'A')
            ba.PB(i-1);
    }

    if (solves())
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}

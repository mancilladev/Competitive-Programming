#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    unordered_map<char, int> hash;
    string s, obj = "Bulbasaur";
    cin >> s;
    for (char c: s)
        hash[c]++;
    hash['a'] /= 2;
    hash['u'] /= 2;
    int res = (1e5);
    for (int i = 0; i < obj.size(); ++i)
        res = min(res, hash[obj[i]]);
    cout << res << '\n';

    return 0;
}

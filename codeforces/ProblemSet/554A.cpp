#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);

int positions(int n) {
    if (n == 1)
        return 2;
    return 1 + positions(n-1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    string s;
    cin >> s;
    cout << positions(s.size())*26 - s.size() << '\n';

    return 0;
}

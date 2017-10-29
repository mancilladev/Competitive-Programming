#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;
    if (a == b) 
        cout << "-1" << endl;
    else
        cout << max(a.size(), b.size()) << endl;

    return 0;
}

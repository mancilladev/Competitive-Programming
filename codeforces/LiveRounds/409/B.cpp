#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
const ll INF = ll(1e18);
string x, y;

bool solves() {
    for (int i = 0; i < x.size(); ++i) {
        if (x[i] < y[i])
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> x >> y;

    if (solves())
        cout << y << endl;
    else
        cout << "-1\n";

    return 0;
}

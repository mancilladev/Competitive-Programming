#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
const ll INF = ll(1e18);
int s, v1, v2, t1, t2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> s >> v1 >> v2 >> t1 >> t2;
    int total1 = t1 * 2 + v1 * s;
    int total2 = t2 * 2 + v2 * s;

    if (total1 < total2)
        cout << "First\n";
    else if (total1 == total2)
        cout << "Friendship\n";
    else
        cout << "Second\n";

    return 0;
}

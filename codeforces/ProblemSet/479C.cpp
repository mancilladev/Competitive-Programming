#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
ll N, M;

struct Node {
    int a;
    int b;
} ;

bool operator <(const Node& x, const Node& y) {
    return x.a < y.a || (x.a == y.a && x.b < y.b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> N;
    vector<Node> arr(N);
    for (int i = 0; i < N; ++i)
        cin >> arr[i].a >> arr[i].b;

    sort(arr.begin(), arr.end());

    int res = arr[0].b;
    for (auto node: arr) {
        if (res > node.b)
            res = node.a;
        else
            res = node.b;
    }
    cout << res << endl;

    return 0;
}

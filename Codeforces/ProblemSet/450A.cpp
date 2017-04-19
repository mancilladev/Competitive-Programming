#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
ll N, M;

struct Node {
    int cur;
    int need;
    int pos;
} node;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> N >> M;
    deque<Node> dq(N);
    for (int i = 0; i < N; ++i)
        cin >> dq[i].need, dq[i].cur = 0, dq[i].pos = i+1;

    while (dq.size() > 1) {
        node = dq.front();
        dq.pop_front();
        node.cur += M;
        if (node.need > node.cur)
            dq.PB(node);
    }

    cout << dq.front().pos << endl;


    return 0;
}

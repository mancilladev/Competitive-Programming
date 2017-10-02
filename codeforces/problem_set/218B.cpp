#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

int N, M;
priority_queue<int> q;
priority_queue<int, vector<int>, greater<int> > min_q;
int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0, x; i < M; ++i) {
        cin >> x;
        q.push(x);
        min_q.push(x);
    }
    int maxi = 0, mini = 0;
    for (int i = 0, x; i < N; ++i) {
        x = q.top(); q.pop(); 
        maxi += x;
        if (x > 1) q.push(x-1);

        x = min_q.top(); min_q.pop(); 
        mini += x;
        if (x > 1) min_q.push(x-1);
    }
    cout << maxi << ' ' << mini << endl;
    return 0;
}

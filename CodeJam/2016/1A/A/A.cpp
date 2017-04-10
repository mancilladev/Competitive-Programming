#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#define F first
#define S second
#define PB push_back
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        string S; cin >> S;
        deque<char> dq;

        for (auto c: S) {
            if (dq.empty() || c >= dq[0])
                dq.push_front(c);
            else
                dq.push_back(c);
        }

        cout << "Case #" << t << ": ";
        for (auto c: dq)
            cout << c;
        cout << '\n';
    }

    return 0;
}

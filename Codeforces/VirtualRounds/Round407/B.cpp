#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;
const ll INF = ll(1e18);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll B, Q, L, M; cin >> B >> Q >> L >> M;
    unordered_set<ll> bad(M);
    ll tmp;
    for (int i = 0; i < M; ++i)
        cin >> tmp, bad.insert(tmp);

    if (abs(B) > L)
        cout << "0\n";
    else if (B == 0 || Q == 1)
        cout << (bad.find(B) != bad.end() ? "0" : "inf") << '\n';
    else if (Q == -1) {
        if (bad.find(B) != bad.end() && bad.find(-B) != bad.end())
            cout << "0\n";
        else
            cout << "inf";
    }
    else if (Q == 0) {
        if (bad.find(0) == bad.end())
            cout << "inf";
        else if (bad.find(B) != bad.end()) cout << "0\n";
        else cout << "1\n";
    }
    else {
        ll res = 0;
        while (abs(B) <= L) {
            if (bad.find(B) == bad.end())
                ++res;
            B *= Q;
        }
        cout << res << '\n';
    }

    return 0;
}

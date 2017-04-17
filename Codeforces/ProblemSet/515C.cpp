#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
ll N, A;
vector<ll> fact {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    string s;
    cin >> N >> s;
    vector<char> res;
    for (auto d: s) {
        if (d == '0' || d == '1')
            continue;
        else if (d == '4')
            res.PB('3'), res.PB('2'), res.PB('2');
        else if (d == '6')
            res.PB('5'), res.PB('3');
        else if (d == '8')
            res.PB('7'), res.PB('2'), res.PB('2'), res.PB('2');
        else if (d == '9')
            res.PB('7'), res.PB('3'), res.PB('3'), res.PB('2');
        else
            res.PB(d);
    }
    sort(res.begin(), res.end(), greater<int>());
    for (auto x: res)
        cout << x;
    cout << endl;

    return 0;
}

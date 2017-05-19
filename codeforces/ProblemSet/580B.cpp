#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
int N, D;

struct Friend {
    ll money;
    ll factor;
} ;

bool operator <(const Friend& x, const Friend& y) {
    return x.money < y.money;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> N >> D;
    vector<Friend> arr(N);
    for (int i = 0; i < N; ++i)
        cin >> arr[i].money >> arr[i].factor;

    sort(arr.begin(), arr.end());

    int p = 0;
    ll res = arr[0].factor;
    ll curmax = arr[0].factor;
    for (int i = 1; i < N; ++i) {
        if (arr[i].money - arr[p].money >= D) {
            while (arr[i].money - arr[p].money >= D)
                curmax -= arr[p].factor, ++p;
        }
        curmax += arr[i].factor;
        res = max(res, curmax);
    }
    cout << res << '\n';

    return 0;
}

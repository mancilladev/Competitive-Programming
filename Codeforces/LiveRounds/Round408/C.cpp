#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <map>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;
const ll INF = ll(1e18);

void del(map<ll, int> & mp, ll x) {
    mp[x]--;
    if (mp[x] == 0)
        mp.erase(x);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<ll> arr(N);
    vector< vector<int> > conn(N);
    map<ll, int> cnt;

    for (int i = 0; i < N; ++i)
        cin >> arr[i], cnt[arr[i]]++;

    for (int i = 0; i < N - 1; ++i) {
        int a, b; cin >> a >> b;
        --a, --b;
        conn[a].PB(b);
        conn[b].PB(a);
    }

    ll res = INF;
    for (int i = 0; i < N; ++i) {
        ll cur = arr[i];
        del(cnt, arr[i]);
        for (int to: conn[i]) {
            cur = max(cur, arr[to] + 1);
            del(cnt, arr[to]);
        }
        if (cnt.size()) {
            auto it = cnt.end();
            it--;
            cur = max(cur, it->F + 2);
        }
        cnt[arr[i]]++;
        for (int neigh: conn[i])
            cnt[arr[neigh]]++;
        res = min(res, cur);
    }
    cout << res << '\n';

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;

const int N = 7400000;
const ll target = 500500;
vector<int> isp(N + 1, 1);
vector<ll> primes;
priority_queue<ll, vector<ll>, greater<ll> > heap;

int main () {
    for (ll i = 2; i < N; ++i) if (isp[i]) {
        primes.PB(i);
        for (ll j = i * i; j < N; j += i) isp[j] = 0;
    }

    ll res = 1;
    int i_p = 0;
    heap.push(primes[i_p]);

    for (int i = 0; i < target; ++i) {
        ll item = heap.top();
        heap.pop();

        res *= item;
        res %= 500500507;

        heap.push(item * item);
        if (item == primes[i_p])
            heap.push(primes[++i_p]);
    }

    cout << res << endl;

    return 0;
}

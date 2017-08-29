#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
int N;

bool isTriangle(ll a, ll b, ll c) {
    return a+b > c && a+c > b && b+c > a;
}

bool existsTriangle(auto& arr) {
    for (int i = 1; i+1 < N; ++i)
        if (isTriangle(arr[i-1], arr[i], arr[i+1]))
            return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> N;
    vector<ll> arr(N);
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    if (existsTriangle(arr))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}

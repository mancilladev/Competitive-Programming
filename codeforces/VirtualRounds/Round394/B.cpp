#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
const ll INF = ll(1e18);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int N, L; cin >> N >> L;
    vector<int> v(N), u(N);
    for (int i = 0; i < N; ++i)
        cin >> v[i];
    for (int i = 0; i < N; ++i)
        cin >> u[i];

    bool res = false;
    for (int i = 0; i < N && !res; ++i) {
        int pos = v[i] - u[0];
        int cnt = 0;
        for (int j = 0; j < N; ++j) {
            if ((pos + u[j])%L != v[(i+j)%N])
                break;
            ++cnt;
        }
        if (cnt == N)
            res = true;
    }
    
    cout << (res ? "YES" : "NO") << '\n';


    return 0;
}

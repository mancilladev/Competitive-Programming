#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
int N, arr[10] {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> N;
    int L = log10(N);
    for (int i = L; i >= 0; --i) {
        int t = pow(10, i);
        arr[i] += (N / t);
        N = N%t;
    }

    vector<int> res;
    for (int i = 0; i < 10; ++i) {
        bool ok = 0;
        for (int j = L; j >= 0; --j) {
            if (ok && arr[j])
                --arr[j], res[res.size()-1] += pow(10, j);
            if (!ok && arr[j])
                --arr[j], ok = 1, res.PB(pow(10,j));
        }
    }
    cout << res.size() << endl;
    for (int x : res)
        cout << x << ' ';
    cout << '\n';

    return 0;
}

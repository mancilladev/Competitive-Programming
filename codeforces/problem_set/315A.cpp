#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

int N, a, b;
int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> N;
    vector<int> A, B;
    for (int i = 0; i < N; ++i) {
        cin >> a >> b;
        A.PB(a);
        B.PB(b);
    }
    int res = 0;
    for (int i = 0; i < N; ++i) {
        int ok = 0;
        for (int j = 0; j < N; ++j) if (j != i && A[i] == B[j]) ok = 1;
        if (!ok) ++res;
    }
    cout << res << endl;
    return 0;
}

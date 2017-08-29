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
int a[100], b[100], c[100];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        string s; cin >> s;
        a[i] = b[i] = c[i] = M;
        for (int j = 0; j < M; ++j) {
            int x = min(j, M-j);
            if (s[j] >= '0' && s[j] <= '9') a[i] = min(a[i], x);
            else if (s[j] >= 'a' && s[j] <= 'z') b[i] = min(b[i], x);
            else c[i] = min(c[i], x);
        }
    }

    int ans = (1e5);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k)
                if (i != j && j != k && i != k) ans = min(ans, a[i]+b[j]+c[k]);
    cout << ans << endl;

    return 0;
}

#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

int N, M;
int main(void) {
# ifdef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
# endif
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> N >> M;
    char c1 = 'B', c2 = 'G';
    if (M > N) swap(M, N), swap(c1, c2);
    while (N || M) {
        if (N > M) cout << c1, --N;
        else cout << c2, --M;
    }
    cout << '\n';
    return 0;
}

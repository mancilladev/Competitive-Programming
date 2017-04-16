#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
const ll INF = ll(1e18);
int N, M;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> N >> M;
    int res = 0;
    vector<bool> cleancol(M, 1), cleanrow(N, 1);

    for (int i = 0; i < N; ++i) {
        string str; cin >> str;
        for (int j = 0; j < M; ++j)
            if (str[j] == 'S')
                cleancol[j] = 0, cleanrow[i] = 0;
    }
    
    int cntR = 0;
    for (auto r: cleanrow)
        if (r)
            ++cntR, res += M;
    for (auto c: cleancol)
        if (c)
            res += N - cntR;

    cout << res << '\n';

    return 0;
}

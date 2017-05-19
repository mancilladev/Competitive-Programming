#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
ll N, M;
vector<string> arr;

bool solves() {
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            int cnt = 0;
            if (y > 0 && arr[y-1][x] == 'o')
                ++cnt;
            if (y < N-1 && arr[y+1][x] == 'o')
                ++cnt;
            if (x > 0 && arr[y][x-1] == 'o')
                ++cnt;
            if (x < N-1 && arr[y][x+1] == 'o')
                ++cnt;
            if (cnt%2 != 0)
                return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> N;
    string s;
    for (int i = 0; i < N; ++i)
        cin >> s, arr.PB(s);

    cout << (solves() ? "YES" : "NO") << endl;

    return 0;
}

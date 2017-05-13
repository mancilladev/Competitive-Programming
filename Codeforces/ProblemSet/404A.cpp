#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef long long ll;
typedef long double ld;
const ll INF = ll(1e18);
const int MAX = 400;
int N;
vector<string> arr(MAX);

bool solves() {
    char x = arr[0][0];
    char o = arr[0][1];
    for (int i = 0; i <= N/2; ++i) {
        for (int j = 0; j <= N/2; ++j) {
            if (i == j) {
                if (arr[i][j] != x || arr[i][N-j-1] != x)
                    return false;
                if (arr[N-i-1][j] != x || arr[N-i-1][N-j-1] != x)
                    return false;
            }
            if (i != j) {
                if (arr[i][j] != o || arr[i][N-j-1] != o)
                    return false;
                if (arr[N-i-1][j] != o || arr[N-i-1][N-j-1] != o)
                    return false;
            }
        }
    }
    return x != o;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    cout << (solves() ? "YES" : "NO") << '\n';

    return 0;
}

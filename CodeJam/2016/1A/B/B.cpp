#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#define F first
#define S second
#define PB push_back
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N; cin >> N;
        vector<int> v, missing;
        set<int> st;
        int tmp;

        for (int i = 0; i < 2 * N - 1; ++i)
            for (int j = 0; j < N; ++j)
                cin >> tmp, v.PB(tmp), st.insert(tmp);

        for (int target: st) {
            int cnt = 0;
            for (int x: v)
                if (x == target) ++cnt;
            if (cnt%2 == 1)
                missing.PB(target);
        }

        cout << "Case #" << t << ": ";
        for (int x: missing)
            cout << x << ' ';
        cout << '\n';
    }

    return 0;
}

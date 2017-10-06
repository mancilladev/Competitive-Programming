#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

int T;
string a, b;
int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> a >> b;
        vector<int> vi = {1,1,1,1,0,0,0,0};
        cout << "[\n";
        do {
            int p = 0, ok = 1;
            string c = "";
            vector<char> stack;
            for (int x : vi) {
                if (!x && !stack.size()) {
                    ok = 0;
                    break;
                }
                if (x) stack.PB(a[p++]);
                else c += stack.back(), stack.pop_back();
            }
            if (ok && c == b) {
                for (int x : vi) cout << (x ? 'i' : 'o') << ' ';
                cout << '\n';
            }
        } while (prev_permutation(vi.begin(), vi.end()));
        cout << "]\n";
    }
    return 0;
}

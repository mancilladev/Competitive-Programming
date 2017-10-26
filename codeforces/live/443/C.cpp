#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<int,int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define error(x) cerr << #x << " = " << x << endl
#define sz(x) (int)(x).size()
#define sq(x) (x) * (x)
#define eb emplace_back
#define pb push_back
#define f first
#define s second
#define endl '\n'

const int INF = 1e9 + 7, MAX = 700031;
int n, cur[MAX], flipped[MAX];

int getbit(int x, int i) {
    return (x >> i)&1;
}

int main(void) {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < 10; ++i) cur[i] = -1;
    for (int i = 0; i < n; ++i) {
        char c; int val;
        cin >> c >> val;
        for (int j = 0; j < 10; ++j) {
            if (c == '^' && getbit(val, j) == 1) {
                flipped[j] ^= 1;
            }
            if (c == '|' && getbit(val, j) == 1) {
                flipped[j] = 0;
                cur[j] = 1;
            }
            if (c == '&' && getbit(val, j) == 0) {
                flipped[j] = 0;
                cur[j] = 0;
            }
        }
    }

    cout << 3 << endl;
    int x = 1023;
    for (int i = 0; i < 10; ++i) if (cur[i] == 0) {
        x -= (1<<i);
    }
    cout << "& " << x << endl;
    x = 0;
    for (int i = 0; i < 10; ++i) if (cur[i] == 1) {
        x |= (1<<i);
    }
    cout << "| " << x << endl;
    x = 0;
    for (int i = 0; i < 10; ++i) if (flipped[i] == 1) {
        x ^= (1<<i);
    }
    cout << "^ " << x << endl;
    return 0;
}

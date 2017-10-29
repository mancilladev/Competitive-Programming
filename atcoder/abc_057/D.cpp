#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define error(x) cerr << #x << " = " << x << endl
#define sz(x) (int)(x).size()
#define eb emplace_back
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1e9 + 7;

int N, A, B;
int main(void) {
    ll C[55][55] = {0};
    C[0][0] = 1;
    for (int i = 1; i <= 50; ++i) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j <= i; ++j)
            C[i][j] = C[i-1][j-1] + C[i-1][j];
    }
    cin >> N >> A >> B;
    vector<ld> arr(N);
    for (int i = 0; i < N; ++i) cin >> arr[i];
    sort(arr.begin(), arr.end(), greater<ld>());
    ld mean = 0;
    for (int i = A; i <= B; ++i) {
        ld sum = 0;
        for (int j = 0; j < i; ++j) sum += arr[j];
        mean = max(mean, sum/i);
    }
    ll ways = 0;
    for (int i = A; i <= B; ++i) {
        ld sum = 0;
        for (int j = 0; j < i; ++j) sum += arr[j];
        if (sum != (ld)round(mean*i)) continue;

        ll last = arr[i-1];
        int more = 0, same = 0;
        for (int j = 0; j < N; ++j) {
            if (arr[j] == last) ++same;
            if (arr[j] > last) ++more;
        }
        int rest = i - more;
        ways += C[same][rest];
    }
    printf("%7Lf\n", mean);
    printf("%lld\n", ways);
    return 0;
}

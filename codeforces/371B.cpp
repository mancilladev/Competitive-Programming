#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
template <class T> using min_queue = priority_queue<T, vector<T>, greater<T>>;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int INF = (int)1e9 + 7;
const long long LLINF = (ll)4e18 + 7;
const double pi = acos(-1.0);

#define deb(x) cerr << #x << " = " << x << endl
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define sq(x) (x) * (x)
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl '\n'

#define UNIQUE(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define FOR(i, a, b) for (int i(a), b_(b); i < b_; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a), b_(b); i >= b_; --i)

const int N = 1e5+7;
int a, b, A[3], B[3];

int main(void) {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> a >> b;
    while (a%2 == 0) A[0]++, a /= 2;
    while (a%3 == 0) A[1]++, a /= 3;
    while (a%5 == 0) A[2]++, a /= 5;
    while (b%2 == 0) B[0]++, b /= 2;
    while (b%3 == 0) B[1]++, b /= 3;
    while (b%5 == 0) B[2]++, b /= 5;
    int suma = abs(A[0] - B[0]) + abs(A[1] - B[1]) + abs(A[2] - B[2]);
    cout << (a == b ? suma : -1) << endl;
    return 0;
}

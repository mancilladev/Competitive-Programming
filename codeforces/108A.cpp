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

const int INF = static_cast<int>(1e9);
const long long LLINF = static_cast<long long>(4e18);
const double pi = acos(-1.0);

#define error(x) cerr << #x << " = " << x << endl
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
int h, m;

void _plus() {
    m = (m + 1)%60;
    if (m == 0) h = (h + 1)%24;
}

int palindromic(vector<int> a, vector<int> b) {
    REP(i, 2) if (a[i] != b[1-i]) return 0;
    return 1;
}

vector<int> digits(int x) {
    return {x/10, x%10};
}

int main(void) {
    scanf("%d:%d", &h, &m);
    _plus();
    while (!palindromic(digits(h), digits(m))) _plus();
    cout << setfill('0') << setw(2) << h << ':';
    cout << setfill('0') << setw(2) << m << endl;
    return 0;
}

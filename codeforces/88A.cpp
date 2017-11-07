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
vector<string> notes {"C","C#","D","D#","E","F","F#","G","G#","A","B","H"};
vector<string> triad(3);

int dist(string a, string b) {
    int pos = distance(notes.begin(), find(all(notes), a));
    FOR(i, 1, sz(notes)) {
        if (notes[(pos+i)%sz(notes)] == b)
            return i;
    }
    return 0;
}

int main(void) {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    REP(i, 3) cin >> triad[i];
    sort(all(triad));
    do {
        int d1 = dist(triad[0], triad[1]);
        int d2 = dist(triad[1], triad[2]);
        if (d1 == 4 && d2 == 3) return cout << "major" << endl, 0;
        if (d1 == 3 && d2 == 4) return cout << "minor" << endl, 0;
    } while (next_permutation(all(triad)));
    cout << "strange" << endl;
    return 0;
}

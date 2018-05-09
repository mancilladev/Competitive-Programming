#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = (int)1e9 + 7;
#define deb(x) cerr << #x << " = " << x << endl
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define sq(x) (x) * (x)
#define fi first
#define se second
#define UNIQUE(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define FOR(i, a, b) for (int i(a); i < b; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a); i >= b; --i)

const int MN = 2e5 + 7;
int N;

int main (void) {
    vector<int> cnt(3, 0);
    set<char> vowels {'a', 'e', 'i', 'o', 'u'};
    REP(i, 3) {
        string s;
        getline(cin, s);
        for (auto c : s) if (vowels.find(c) != vowels.end()) ++cnt[i];
    }
    cout << (cnt[0] == 5 && cnt[1] == 7 && cnt[2] == 5 ? "YES" : "NO") << '\n';
    return 0;
}

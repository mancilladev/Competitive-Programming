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
string S;

bool zo (int n1, int n0) {
    int n = sz(S);
    return n0<(n-2)/2+2 && n1+(S[n-1]=='?')<(n-2+1)/2+2 && S[n-1]!='0';
}

bool oz (int n1, int n0) {
    int n = sz(S);
    return n0+(S[n-1]=='?')<(n-2)/2+2 && n1<(n-2+1)/2+2 && S[n-1]!='1';
}

int main (void) {
    while (cin >> S) {
        int ones = 0;
        int zeros = 0;
        int q = 0;
        for (auto c : S) {
            if (c == '1') ++ones;
            if (c == '0') ++zeros;
            if (c == '?') ++q;
        }
        if (zeros + q > ones) cout << "00\n";
        if (zo(ones, zeros)) cout << "01\n";
        if (oz(ones, zeros)) cout << "10\n";
        if (ones + q > zeros + 1) cout << "11\n";
    }
    return 0;
}

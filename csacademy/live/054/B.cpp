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

const int INF = 1e9 + 7;
int N, acvals[30] = {0};
vector<string> arr;
string acronym;

int check(int x) {
    if (sz(arr[x]) > sz(acronym)) return 0;

    int a[30] = {0};
    for (auto c : arr[x]) a[c - 'a']++;
    for (int i = 0; i < 30; ++i)
        if (a[i] > acvals[i])
            return 0;
    return 1;
}

int main(void) {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string s; cin >> s;
        arr.pb(s);
        acronym += s[0];
        acvals[s[0] - 'a']++;
    }
    int res = 0;
    for (int i = 0; i < N; ++i) {
        acvals[acronym[i] - 'a']--;
        if (check(i)) ++res;
        acvals[acronym[i] - 'a']++;
    }
    cout << res << endl;
    return 0;
}

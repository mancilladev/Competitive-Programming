#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

string s1, s2;
int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> s1 >> s2;
    if (s1.size() != s2.size()) return cout << "NO\n", 0;
    vector<int> arr(50);
    for (int i = 0; i < (int)s1.size(); ++i)
        arr[s1[i] - 'a']++, arr[s2[i] - 'a']--;
    for (int i = 0; i <= 'z'-'a'; ++i)
        if (arr[i] != 0) return cout << "NO\n", 0;
    int cnt = 0;
    for (int i = 0; i < (int)s1.size(); ++i)
        if (s1[i] != s2[i]) ++cnt;
    cout << (cnt == 2 ? "YES" : "NO") << endl;
    return 0;
}

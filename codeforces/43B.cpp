#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

string s1, s2;
int arr[1007];
int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    getline(cin, s1);
    getline(cin, s2);
    for (char c : s1) if (c != ' ') arr[c - 'A']++;
    for (char c : s2) {
        if (c == ' ') continue;
        if (arr[c - 'A'])
            arr[c - 'A']--;
        else
            return cout << "NO\n", 0;
    }
    cout << "YES\n";
    return 0;
}

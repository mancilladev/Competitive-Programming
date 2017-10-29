#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;

string S;
int arr[100];
int main(void) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    cin >> S;
    for (char c : S) arr[c - 'a']++;
    int odd = 0;
    for (int i = 0; i + 'a' <= 'z'; ++i) if (arr[i]&1) odd++;
    cout << ((odd == 0 || odd&1) ? "First" : "Second") << endl;
    return 0;
}

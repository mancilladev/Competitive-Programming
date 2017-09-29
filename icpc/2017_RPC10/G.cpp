#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(0), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        string S;
        cin.ignore();
        getline(cin, S);

        istringstream iss(S);
        vector<int> a;
        for (int x; iss>>x; )
            a.push_back(x);

        int top = *max_element(a.begin(), a.end());
        int res = 0;
        bool start = 0;
        cout << '\n' << a.size() << endl;
        for (int x : a) {
            if (x == top) ++res, start = !start;
            else if (start) ++res;
            cout << x << ' ' << start << ' ' << res << endl;
        }
        cout << res << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;

multiset<int> st;
int T, N;
int main () {
    cin >> T;
    while (T--) {
        cin >> N;
        st.clear();
        for (int i = 0, x; i < N; ++i) {
            cin >> x;
            st.insert(x);
            auto it = st.upper_bound(x);
            if (it != st.end()) st.erase(it);
        }
        cout << st.size() << endl << endl;
    }
}

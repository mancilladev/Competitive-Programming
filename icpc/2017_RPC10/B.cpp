#include <bits/stdc++.h>
using namespace std;

multiset<int> st;
int T, N, lis[1007], lds[1007], arr[1007];
int main () {
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; ++i) cin >> arr[i];

        st.clear();
        for (int i = 0; i < N; ++i) {
            st.insert(arr[i]);
            auto it = st.upper_bound(arr[i]);
            if (it != st.end()) st.erase(it);
            lis[i] = st.size();
        }


        st.clear();
        for (int i = N-1; i >= 0; --i) {
            st.insert(arr[i]);
            auto it = st.upper_bound(arr[i]);
            if (it != st.end()) st.erase(it);
            lds[i] = st.size();
        }

        int res = lds[N-1];
        for (int i = 0; i < N-1; ++i)
            res = max(res, lis[i] + lds[i+1]);
        cout << res << '\n';
    }
}

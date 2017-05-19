#include <iostream>
#include <string>
#include <set>
using namespace std;

int main () {
    string s; cin >> s;
    set<int> st;
    set<int>::iterator it;

    for (int i = 0; i < s.length(); i++) {
        int cur = s[i] - 'a';
        st.insert(cur);
        it = st.find(cur);
        it++;
        if (it != st.end())
            st.erase(it);
    }

    cout << 26 - st.size() << endl;
}

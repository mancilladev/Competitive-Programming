#ifdef JUDGE
#include <fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, tmp;
    cin >> n;

    multiset<int> st;
    for (int i = 0; i < n; i++)
        cin >> tmp, st.insert(tmp);

    int k;
    cin >> k;

    int t = 0;
    int i;
    while (n > 1) {
        auto rit = st.rbegin();
        if (*rit - t <= 0) break;

        tmp = max(*rit-(k-1), 0);
        rit++;
        while (*(rit) <= tmp && tmp - t > 1)
            tmp = max(tmp-(k-1), 0), t++;
        rit--;
        st.erase(next(rit).base());
        st.insert(tmp);
        t++;
    }

    if (n == 1)
        t = *st.begin()/k + (*st.begin()%k ? 1 : 0);

    cout << t << '\n';

    return 0;
}

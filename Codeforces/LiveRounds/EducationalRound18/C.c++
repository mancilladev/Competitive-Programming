#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string clean(string s) {
    int cur = 0;
    while (cur + 1 < s.size() && s[cur] == '0')
        ++cur;
    return s.substr(cur);
}

int main () {
    string s; cin >> s;
    int sum = 0;

    for (int i = 0; i < s.size(); ++i)
        sum += (s[i] - '0');

    sum %= 3;
    string ans = "";
    if (sum != 0) {
        for (int i = s.size() - 1; i >= 0; --i) {
            if ((s[i] - '0')%3 == sum) {
                string t = s.substr(0, i) + s.substr(i + 1);
                t = clean(t);
                if (t.size() > ans.size())
                    ans = t;
                break;
            }
        }
        int d1 = -1;
        for (int i = s.size() - 1; i >= 0; --i) {
            if ((s[i] - '0')%3 == 0)
                continue;
            if ((s[i] - '0')%3 == sum)
                continue;
            if (d1 == -1) {
                d1 = i;
                continue;
            }
            string t = s.substr(0, i) + s.substr(i + 1, d1 - i - 1) + s.substr(d1 + 1);
            t = clean(t);
            if (t.size() > ans.size())
                ans = t;
            break;
        }
    }
    else {
        ans = s;
    }

    if (ans.empty())
        cout << "-1" << '\n';
    else
        cout << ans << '\n';

    return 0;
}

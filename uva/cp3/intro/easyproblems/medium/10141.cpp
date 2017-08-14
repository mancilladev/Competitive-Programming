#include <bits/stdc++.h>
using namespace std;

struct Proposal {
    string name;
    float d;
    int r;
    int id;
    bool operator<(const Proposal& x) const {
        const int a = -r, xa = -x.r;
        return tie(a, d, id) < tie(xa, x.d, x.id);
    }
};

int main () {
    int n, p;
    string s;
    int T = 1;

    while (cin >> n >> p, (n || p)) {
        cin.ignore();
        set<Proposal> list;
        int id = 0;

        while (n--) getline(cin, s);
        while (p--) {
            Proposal prop;
            getline(cin, prop.name);
            cin >> prop.d >> prop.r;
            cin.ignore();
            for (int i = 0; i < prop.r; ++i)
                getline(cin, s);
            prop.id = id++;
            list.insert(prop);
        }
        if (T > 1)
            cout << endl;
        cout << "RFP #" << T++ << '\n';
        cout << (*list.begin()).name << '\n';
    }

    return 0;
}

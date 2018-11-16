#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define deb(x) cout << #x << " = " << x << endl
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define fore(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define ford(i, n) for (int i = (int)(n) -1; i >= 0; --i)

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

struct Red
{
    string name;
    int id;
    int taxi;
    int pizza;
    int girls;
    Red (string s, int x) : name(s), id(x), taxi(0), pizza(0), girls(0) {}
    void add_number(string num) {
        vector<int> v;
        for (auto c : num) if ('0' <= c && c <= '9') {
            v.push_back(c - '0');
        }
        // taxi
        bool t = true;
        for (auto x : v) if (x != v[0]) t = false;
        if (t) {
            ++taxi;
            return;
        }
        // pizza
        bool p = true;
        for1(i, sz(v)-1) if (v[i] >= v[i-1]) p = false;
        if (p) {
            ++pizza;
            return;
        }
        // girl
        ++girls;
    }
};

int main (void) {
    ios::sync_with_stdio(false), cin.tie(0);
    cout.precision(10), cout << fixed;

    int n;
    while (cin >> n) {
        vector<Red> arr;
        forn(i, n) {
            int m;
            string s;
            cin >> m >> s;
            Red r = Red(s, i);
            forn(j, m) {
                cin >> s;
                r.add_number(s);
            }
            arr.push_back(r);
        }
        // taxi
        sort(all(arr), [](const Red& r1, const Red& r2) {
            if (r1.taxi == r2.taxi)
                return r1.id < r2.id;
            return r1.taxi > r2.taxi;
        });
        cout << "If you want to call a taxi, you should call: ";
        forn(i, n) {
            if (arr[i].taxi != arr[0].taxi)
                break;
            if (i)
                cout << ", ";
            cout << arr[i].name;
        }
        cout << ".\n";
        // pizza
        sort(all(arr), [](const Red& r1, const Red& r2) {
            if (r1.pizza == r2.pizza)
                return r1.id < r2.id;
            return r1.pizza > r2.pizza;
        });
        cout << "If you want to order a pizza, you should call: ";
        forn(i, n) {
            if (arr[i].pizza != arr[0].pizza)
                break;
            if (i)
                cout << ", ";
            cout << arr[i].name;
        }
        cout << ".\n";
        // girls
        sort(all(arr), [](const Red& r1, const Red& r2) {
            if (r1.girls == r2.girls)
                return r1.id < r2.id;
            return r1.girls > r2.girls;
        });
        cout << "If you want to go to a cafe with a wonderful girl, you should call: ";
        forn(i, n) {
            if (arr[i].girls != arr[0].girls)
                break;
            if (i)
                cout << ", ";
            cout << arr[i].name;
        }
        cout << ".\n";
    }
    return 0;
}

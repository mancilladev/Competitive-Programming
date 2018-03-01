#include <bits/stdc++.h>
using namespace std;
typedef long double ll;
typedef pair<ll,ll> pii;
#define sz(a) (int)(a).size()
#define sq(a) (a)*(a)
#define mp make_pair
#define x first
#define y second

const int N = 107, INF = 1e9;
int n;
pii pts[N];
vector<pii> top, bot;

// PAIR
template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
    return os << "(" << p.first << ", " << p.second << ")";
}

ll mag(pii p) {
    return sqrt(sq(p.x) + sq(p.y));
}

pii resta(pii a, pii b) {
    return mp(b.x - a.x, b.y - a.y);
}

int cross_product2(pii a, pii b) {
    return (a.x * b.y) - (a.y * b.x);
}

int cross_product(pii p1, pii p2, pii p3) {
    pii a = resta(p1, p2);
    pii b = resta(p2, p3);
    return (a.x * b.y) - (a.y * b.x);
}

ll dist(pii s1, pii s2, pii p) {
    return fabs(cross_product2(resta(p,s1),resta(p,s2)) / mag(resta(s1,s2)));
}

bool removedLeftTurnsFromTop() {
    if (sz(top) < 3) return false;
    pii p1 = top[sz(top)-3];
    pii p2 = top[sz(top)-2];
    pii p3 = top[sz(top)-1];
    if (cross_product(p1, p2, p3) > 0) {
        pii last = top.back();
        top.pop_back(); top.pop_back();
        top.push_back(last);
        return true;
    }
    return false;
}

bool removedRightTurnsFromBottom() {
    if (sz(bot) < 3) return false;
    pii p1 = bot[sz(bot)-3];
    pii p2 = bot[sz(bot)-2];
    pii p3 = bot[sz(bot)-1];
    if (cross_product(p1, p2, p3) < 0) {
        pii last = bot.back();
        bot.pop_back();
        bot.pop_back();
        bot.push_back(last);
        return true;
    }
    return false;
}

int main(void) {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> pts[i].x >> pts[i].y;
    sort(pts, pts + n);

    top.push_back(pts[0]);
    top.push_back(pts[1]);
    bot.push_back(pts[0]);
    bot.push_back(pts[1]);

    for (int i = 2; i < n; ++i) {
        top.push_back(pts[i]);
        bot.push_back(pts[i]);
        while (removedLeftTurnsFromTop());
        while (removedRightTurnsFromBottom());
    }

    vector<pii> hull;
    for (auto p : top) hull.push_back(p);
    for (int i = sz(bot)-2; i >= 1; --i) hull.push_back(bot[i]);

#ifdef dgb
    cout << "TOP\n";
    for (auto p : top) cout << p << '\n';
    cout << "\nBOTTOM\n";
    for (auto p : bot) cout << p << '\n';

    cout << "\nHULL\n";
    for (auto p : hull) cout << p << '\n';
    cout << '\n';
#endif

    long double res = INF;
    for (int i = 0; i < sz(hull); ++i) {
        long double lgst = 0;
        for (int j = 0; j < sz(hull); ++j) {
            if (j == i || j == (i+1)%sz(hull)) continue;
            //cout << hull[i] << ' ' << hull[(i+1)%sz(hull)] << ' ' << hull[j] << ' ';
            //cout << dist(hull[i], hull[(i+1)%sz(hull)], hull[j]) << endl;
            lgst = max(lgst, dist(hull[i], hull[(i+1)%sz(hull)], hull[j]));
        }
        res = min(res, lgst);
    }
    cout << fixed << setprecision(15) << res << endl;

    return 0;
}

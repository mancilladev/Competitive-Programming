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

template <class T>
class fraction {
private:
    T gcd(T a, T b) { return b == T(0) ? a : gcd(b, a % b); }
public:
    T n, d;
    fraction(T n_, T d_) {
        assert(d_ != 0);
        n = n_, d = d_;
        if (d < T(0)) n = -n, d = -d;
        T g = gcd(abs(n), abs(d));
        n /= g, d /= g; }
    fraction(T n_) : n(n_), d(1) { }
    fraction(const fraction<T>& other) : n(other.n), d(other.d) { }
    fraction<T> operator +(const fraction<T>& other) const {
        return fraction<T>(n * other.d + other.n * d, d * other.d);}
    fraction<T> operator -(const fraction<T>& other) const {
        return fraction<T>(n * other.d - other.n * d, d * other.d);}
    fraction<T> operator *(const fraction<T>& other) const {
        return fraction<T>(n * other.n, d * other.d); }
    fraction<T> operator /(const fraction<T>& other) const {
        return fraction<T>(n * other.d, d * other.n); }
    bool operator <(const fraction<T>& other) const {
        return n * other.d < other.n * d; }
    bool operator <=(const fraction<T>& other) const {
        return !(other < *this); }
    bool operator >(const fraction<T>& other) const {
        return other < *this; }
    bool operator >=(const fraction<T>& other) const {
        return !(*this < other); }
    bool operator ==(const fraction<T>& other) const {
        return n == other.n && d == other.d; }
    bool operator !=(const fraction<T>& other) const {
        return !(*this == other); }
    explicit operator double() const {
        return double(n) * double(d); }
};
template < typename T >
ostream& operator << ( ostream& os, const fraction< T > & f ) {
    return os << f.n << "/" << f.d;
}

int main (void) {
    ios::sync_with_stdio(false), cin.tie(0);
    cout.precision(10), cout << fixed;

    int a, b, c, d;
    while (cin >> a >> b >> c >> d) {
        fraction<int> p = fraction<int>(a, b);
        fraction<int> q = (fraction<int>(1) - fraction<int>(c, d)) * (fraction<int>(1) - p);
        fraction<int> res = p / (fraction<int>(1) - q);
        cout << double(res) << '\n';
    }
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main () {
    long long k, a, b;
    long long cnt = 0;
    cin >> k >> a >> b;

    if (b < 0) {
        b = -b;
        a = -a;
        swap(a, b);
    }
    if (b >= 0) {
        cnt += b / k;
        if (a <= 0) {
            a = -a;
            cnt += a/k+1;
        }
        else {
            --a;
            cnt -= a/k;
        }
    }
    
    cout << cnt << endl;
}

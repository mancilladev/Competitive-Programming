#include <iostream>
#include <vector>
using namespace std;

int gcd(int x, int y) {
        if (y == 0) return x;
        return gcd(y, x%y);
}

int main () {
        vector<double> antiprimes = {2, 4, 6, 12, 24, 36, 48, 60, 120, 180, 240, 360, 720, 840, 1260, 1680, 2520, 5040, 7560, 10080, 15120, 20160, 25200, 27720, 45360, 50400, 55440, 83160, 110880, 166320, 221760, 277200, 332640, 498960, 554400, 665280, 720720};
        double m_phi = 0;
        int ans = 0;
        for (auto i: antiprimes) {
                int coprimes = 0;
                for (int j = i-1; j > 0; j--) {
                        if (gcd(i, j) == 1) coprimes++;
                }
                // cout<<i<<" "<<coprimes<<" "<<i/coprimes<<endl;
                if (i/coprimes > m_phi) {
                        ans = i;
                        m_phi = i/coprimes;
                }
        }
        cout<<ans<<endl;
}

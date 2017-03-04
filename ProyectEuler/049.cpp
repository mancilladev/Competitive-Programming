#include <iostream>
#include <vector>
using namespace std;

bool isPerm(int x, int y) {
        vector<int> a(10, 0), b(10, 0);
        while (x) {
                a[x%10]++;
                x/=10;
        }
        while (y) {
                b[y%10]++;
                y/=10;
        }
        for (int i = 0; i < 10; i++)
                if (a[i] != b[i])
                        return false;
        return true;
}

int main () {
        vector<int> p;
        vector<bool> isp(10000, 1);
        isp[0] = 0; isp[1] = 0;
        for (int i = 2; i < isp.size(); i++)
                if (isp[i]) {
                        p.push_back(i);
                        for (int j = i*i; j < isp.size(); j+=i)
                                isp[j] = 0;
                }

        for (int i = lower_bound(p.begin(), p.end(), 1000)-p.begin(); i < p.size(); i++)
                for (int j = i + 1; j < p.size(); j++) {
                        int diff = p[j] - p[i];
                        int k = p[j] + diff;
                        if (k > 1000 && k < 10000 && isp[k] && isPerm(k, p[j]) && isPerm(k, p[i])) {
                                cout<<p[i]<<" "<<k<<" "<<p[j]<<endl;
                        }
                }
}

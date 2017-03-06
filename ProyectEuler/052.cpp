#include <iostream>
#include <vector>
using namespace std;

bool isPerm(long long a, long long b) {
        vector<int> s1(10), s2(10);
        while (a) {
                s1[a%10]++;
                a /= 10;
        }
        while (b) {
                s2[b%10]++;
                b /= 10;
        }
        for (int i = 0; i < s1.size(); i++)
                if (s1[i] != s2[i])
                        return false;
        return true;
}

int main () {
        long long x = 0;
        while (++x) {
                int i = 6;
                for (; i > 0; i--) {
                        if (!isPerm(x, i*x))
                                break;
                }
                if (i == 0) {
                        cout<<x<<endl;
                        return 0;
                }
        }
}

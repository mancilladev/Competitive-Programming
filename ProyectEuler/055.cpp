#include <iostream>
using namespace std;

unsigned long long r, n;

bool nIsPalindrome () {
        unsigned long long x = n;
        int d;
        r = 0;
        while (x > 0) {
                d = x%10;
                r = r*10 + d;
                x /= 10;
        }
        return n == r;
}

int main () {
        int Ln = 10000;

        for (int i = 0; i < 10000; i++) {
                n = i;
                nIsPalindrome();
                n += r;
                for (int j = 0; j < 48; j++) {
                        if (nIsPalindrome()) {
                                Ln--; break;
                        }
                        n += r;
                }
        }
        cout<<Ln<<endl;
}

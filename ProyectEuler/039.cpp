#include <iostream>
#include <cmath>
using namespace std;

int main () {
        int cntmax = 0;
        int pmax = 0;

        for(int p = 1; p <= 1000; p++) {
                int cnt = 0;

                for (int a = 1; a < p; a++) {
                        for (int b = 1; b < p - a; b++) {
                                int c = p - a - b;
                                if(a*a + b*b == c*c)
                                        cnt++;
                        }
                }

                if(cnt > cntmax) {
                        cntmax = cnt;
                        pmax = p;
                }
        }

        cout<<pmax<<endl;
}

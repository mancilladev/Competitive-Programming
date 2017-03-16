#include <iostream>
#include <vector>
using namespace std;

int npf(long long n) {
        int cnt = 0;
        for (int i = 2; i <= n; i++) {
                if(n%i == 0) {
                        while(n%i == 0)
                                n /= i;
                        cnt++;
                }
        }
        return cnt;
}

bool fpf(long long n) {
        return npf(n) == 4;
}

int main () {
        long long i = 0;
        int j;
        while(true) {
                for (j = 3; j >= 0; j--) {
                        if(!fpf(i+j)) {
                                i+=j+1;
                                break;
                        }
                }
                if (j == -1) {
                        cout<<i<<endl;
                        return 0;
                }
        }
        cout<<"wat"<<endl;
}

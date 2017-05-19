#include<iostream>
#include<vector>
using namespace std;

vector<long long> v(4);

bool isPrime(long long p) {
        for (int i = 2; i * i <= p; i++)
                if (p%i == 0)
                        return false;
        return true;
}

void setCorners(int x) {
        v[0] = 4*x*x + 2*x + 1;
        v[1] = 4*x*x - 2*x + 1;
        v[2] = 4*x*x + 4*x + 1;
        v[3] = 4*x*x + 1;
}

int main () {
        int i = 0;
        int p = 0;
        while (++i) {
                setCorners(i);
                for (auto n: v)
                        if (isPrime(n))
                                p++;
                if (100.0 * p / (4.0 * i + 1) < 10)
                        break;
        }
        cout<<i*2+1<<endl;
        return 0;
}

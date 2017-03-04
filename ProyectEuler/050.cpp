#include <iostream>
#include <vector>
#define N 1000000
using namespace std;

int main () {
        vector<long long> v;
        vector<bool> isprime(N, 1);
        isprime[0] = 0;
        isprime[1] = 0;
        for (int i = 2; i < isprime.size(); i++)
                if (isprime[i]) {
                        v.push_back(i);
                        for (int j = i*i; j < isprime.size(); j+=i)
                                isprime[j] = 0;
                }

        int l = 0, r;
        long long suml = 0, sumr = 0;
        for (r = 0; suml+v[r] <= N; r++) {
                suml+=v[r]; sumr+=v[r];
        }
        r--;

        while (true) {
                suml -= v[r];
                sumr -= v[l];
                if (isprime[suml]) {
                        cout<<suml<<endl;
                        return 0;
                }
                if (isprime[sumr]) {
                        cout<<sumr<<endl;
                        return 0;
                }
                r--; l++;
        }
}

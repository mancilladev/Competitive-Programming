#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

#define MAX 10000007

bool np[MAX] = {};

void sieve() {
    np[0] = 1;
    np[1] = 1;
    for(ll i=2; i*i<MAX; i++)
        if(!np[i])
            for(ll j=i*i; j<MAX; j+=i)
                np[j] = 1;
}


int main() {
    sieve();
    int T; cin>>T;
    while(T--) {
        int N; cin>>N;

        ll i=0;
        while(N)
            if(np[++i] == 0) N--;
        cout<<i<<endl;
    }
    return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
typedef long long ll;

#define MAX 1000007


int main() {
    ll p[MAX];
    for(ll i = 0; i != MAX; i++) p[i] = i;

    p[1] = 0;
    for(ll i = 2; i != MAX; i++) {
        if(p[i])
            for(ll j = i*i; j < MAX; j+=i)
                p[j] = 0;
        p[i] += p[i-1];
    }

    int T; cin>>T;
    while(T--) {
        int N; cin>>N;
        cout<<p[N]<<endl;
    }
    return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll biggest_factor(ll n){
    for(ll i=2;;i++){
        if(i*i > n)
            return n;
        if(n%i == 0)
            return max(i, biggest_factor(n/i));
    }
}

int main() {
    int T;
    cin>>T;
    while(T--){
        ll N;
        cin >> N;
        cout<<biggest_factor(N)<<endl;
    }
    return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


long long tri(long long n) {
    return n*(n+1)/2;
}


long long divisors(long long n) {
    long long cnt = 0;
    long long i = 1;
    for(; i * i < n; i++)
        if(n%i == 0)
            cnt += 2;
    if(i * i == n)
        cnt++;
    return cnt;
}


int main() {
    vector< pair<int,int> > v {
        {1, 1},
        {2, 2},
        {3, 4},
        {7, 6},
        {8, 9},
        {15, 16},
        {24, 18},
        {32, 20},
        {35, 24},
        {63, 36},
        {80, 40},
        {104, 48},
        {224, 90},
        {384, 112},
        {560, 128},
        {935, 144},
        {1224, 162},
        {1664, 168},
        {1728, 192},
        {2015, 240},
        {2079, 320},
        {5984, 480},
        {12375, 576},
        {14399, 648},
        {21735, 768},
        {41040, 1024}
    };

    int T; cin>>T;
    while(T--) {
        int N; cin>>N;
        for(int i = 0; i != v.size(); i++) {
            if(v[i].second > N) {
                cout<<tri(v[i].first)<<endl;
                break;
            }
        }
    }
    return 0;
}

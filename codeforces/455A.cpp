#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define spresent(str1,str2) (str1.find(str2) != string::npos)

#define MAX 100007

int main() {
    int n;
    while(cin>>n) {
        long long cnt[MAX] = {};
        int temp;
        int big = 0;
        REP(i,n) {
            cin>>temp;
            cnt[temp]++;
            big = max(temp, big);
        }

        long long f[MAX] = {};
        f[1] = cnt[1];
        FOR(i,2,big)
            f[i] = max(f[i-1],f[i-2]+cnt[i]*i);
        cout<<f[big]<<endl;
    }
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define spresent(str1,str2) (str1.find(str2) != string::npos)

int main() {
    int N, K;
    while(cin>>N>>K) {
        vector<int> v(N);
        REP(i,N) cin>>v[i];
        sort(v.begin(), v.end());

        int res = 0;
        for(int i = 0; i+3 <= N; i+=3) {
            if(5 - v[i+2] >= K) res++;
            else break;
        }
        cout<<res<<endl;
    }
}

#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define spresent(str1,str2) (str1.find(str2) != string::npos)

int main() {
    int n;
    while(cin>>n) {
        vector<int> v(n);
        REP(i,n) cin>>v[i];

        int small = v[0];
        int big = v[0];
        int res = 0;
        FOR(i,1,n-1) {
            if(v[i] > big) {
                big = v[i];
                res++;
            }
            else if(v[i] < small) {
                small = v[i];
                res++;
            }
        }
        cout<<res<<endl;
    }
}

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

int main() {
    int n,l;
    cout.precision(11);
    while(cin>>n>>l) {
        vector<int> v(n);
        REP(i,n) cin>>v[i];
        sort(v.begin(), v.end());

        double dist = 0;
        dist = max(v[0], l-v.back());
        FOR(i,1,n-1) dist = max(dist, (double)(v[i]-v[i-1])/2);
        cout<<dist<<endl;
    }
}

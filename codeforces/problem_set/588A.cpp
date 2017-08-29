#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define spresent(str1,str2) (str1.find(str2) != string::npos)

int main() {
    int N;
    while(cin>>N) {
        vector< pair<int,int> > v(N);
        REP(i,N)
            cin>>v[i].first>>v[i].second;

        int res = 0;
        int meat = 0;
        REP(i,N) {
            if(meat) {
                meat -= v[i].first;
                continue;
            }
            res += (v[i].first * v[i].second);
            int j = i+1;
            while(j < N && v[i].second < v[j].second) {
                meat += v[j].first;
                res += (v[j].first * v[i].second);
                j++;
            }
        }

        cout<<res<<endl;
    }
}

#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define F(i,L,R) for(int i=L; i<R; i++)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;

int main() {
    int n;
    while(cin>>n) {
        int minnum = 0;
        int curr = 0;
        vector< pair<int,int> > trams(n);
        F(i,0,n) cin>>trams[i].first>>trams[i].second;
        F(i,0,n) {
            curr -= trams[i].first;
            curr += trams[i].second;
            minnum = max(minnum, curr);
        }
        cout<<minnum<<endl;
    }
}

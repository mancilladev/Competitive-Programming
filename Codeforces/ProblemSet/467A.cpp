#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define F(i,L,R) for(int i=L; i<R; i++)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
#define spresent(str1,str2) (str1.find(str2) != string::npos)

int main() {
    int n;
    while(cin>>n) {
        int cnt = 0;
        vector< pair<int,int> > rooms(n);
        F(i,0,n) cin>>rooms[i].first>>rooms[i].second;
        F(i,0,n) if(rooms[i].second - rooms[i].first > 1) cnt++;
        cout<<cnt<<endl;
    }
}

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define F(i,L,R) for(int i=L; i<R; i++)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
#define spresent(str1,str2) (str1.find(str2) != string::npos)


bool PairCompare(const pi& a, const pi& b) {
    return a.first < b.first;
}


int main() {
    int s, n;
    while(cin>>s>>n) {
        int x, y;
        vector<pi> dragons(n);
        F(i,0,n) cin>>dragons[i].first>>dragons[i].second;
        sort(dragons.begin(), dragons.end(), PairCompare);

        bool win = true;
        F(i,0,n) {
            if(s <= dragons[i].first) {
                win = false;
                break;
            }
            else {
                s+=dragons[i].second;
            }
        }
        if(win) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

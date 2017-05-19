#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define F(i,L,R) for(int i=L; i<R; i++)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
#define spresent(str1,str2) (str1.find(str2) != string::npos)

int main() {
    int n, temp;
    while(cin>>n) {
        pair<int,int> pos;
        vector<vi> m(5, vi(5.0));
        m[0][0] = n;
        F(i,0,5) {
            F(j,0,5) {
                if(!i && !j) continue;
                cin>>m[i][j];
                if(m[i][j]) {
                    pos.first = i;
                    pos.second = j;
                }
            }
        }
        cout<<abs(pos.first-2)+abs(pos.second-2)<<endl;
    }
}

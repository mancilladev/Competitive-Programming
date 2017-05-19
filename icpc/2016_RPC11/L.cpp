#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<string> vs;
#define INF 1000000000
#define max(a,b) (a<b?b:a)
#define min(a,b) (a<b?a:b)
#define abs(x) (x<0?(-x):x) // big bug here if "-x" is not surrounded by "()"
#define F(i,L,R) for (int i = L; i < R; i++) //next four are for "for loops"
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define FF(i,L,R) for (int i = L; i > R; i--)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
// F(u,0,n){F(w,0,m)cout<<array[u][w]<<" ";cout<<endl;} print Matrix
// int array[n][m] = {}; this initializes array with zeros


int filltile(vector<vi> &tile, int i, int j, int size=1) {
    int val = tile.at(i).at(j);
    tile[i][j] = (val!=0)?-val:-9;
    if(( i+1 )<tile.size() && tile[i+1][j] == val) size = filltile(tile,i+1,j, ++size);
    if(( j+1 )<(tile.at(0).size()) && tile[i][j+1] == val) size = filltile(tile,i,j+1, ++size);
    if(( j-1 )>=0 && tile[i][j-1] == val) size = filltile(tile,i,j-1, ++size);
    return size;
}


int main() {
    int a, b;
    while(cin>>a>>b) {
        vector<vi> tile;
        int temp;
        int smallest = a*b;
        F(i,0,a) {
            vi tempv;
            F(j,0,b) {
                cin>>temp;
                tempv.push_back(temp);
            }
            tile.push_back(tempv);
        }
        F(i,0,a) {
            F(j,0,b) {
                if(tile[i][j]>=0) {
                    temp = filltile(tile,i,j);
                    if(temp<smallest) smallest = temp;
                }
            }
        }
        cout<<smallest<<endl;
    }
    return 0;
}

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


bool lessthan(ll grid[], ll temp[], ll len) {
    F(i,0,len) if(grid[i]<temp[i]) return false;
    return true;
}


int main() {
    ll len;
    while(cin>>len) {
        ll size = 0;
        ll grid[len], pir[len], temp[len];
        F(z,0,len) pir[z]=0;
        F(z,0,len) temp[z]=0;
        F(i,0,len) {
            cin>>grid[i];
        }
        // F(i,0,len) cout<<grid[i]<<" ";
        // cout<<endl;
        // F(i,0,len) cout<<temp[i]<<" ";
        // cout<<endl;
        F(i,0,len) {
            while(true) {
                if(i+(size*2+1)>len) break;
                size++;
                F(j,0,size) temp[j+i] = j+1;
                FF(j,size,0) temp[i+2*(size-1)-(j-1)] = j;
                if (lessthan(grid,temp, len)) {
                    copy(temp, temp+len, pir);
                    // F(j,0,len) cout<<pir[j]<<" ";
                    // cout<<endl;
                } else {
                    F(z,0,len) temp[z]=0;
                    size--;
                    break;
                }
            }
        }
        cout<<size<<endl;
    }
    return 0;
}

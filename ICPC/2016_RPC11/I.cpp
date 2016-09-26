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
typedef vector<ll> vl;
#define INF 1000000000
#define max(a,b) (a<b?b:a)
#define min(a,b) (a<b?a:b)
#define abs(x) (x<0?(-x):x) // big bug here if "-x" is not surrounded by "()"
#define F(i,L,R) for (int i = L; i < R; i++) //next four are for "for loops"
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define FF(i,L,R) for (int i = L; i > R; i--)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define DBG(x) cout<<#x<<" = "<<(x)<<endl;
// F(u,0,n){F(w,0,m)cout<<array[u][w]<<" ";cout<<endl;} print Matrix
// int array[n][m] = {}; this initializes array with zeros

int main() {
    int w;
    while(cin>>w) {
        // receive array
        vi grid(w);
        F(i,0,w) cin>>grid[i];

        // smooth first part
        grid[0] = 1;
        F(i,1,w) grid[i] = min(grid[i],grid[i-1]+1);

        // smooth second part
        grid[w-1] = 1;
        FF(i,w-2,0) grid[i] = min(grid[i],grid[i+1]+1);

        cout<<*max_element(grid.begin(), grid.end())<<endl;
    }
    return 0;
}

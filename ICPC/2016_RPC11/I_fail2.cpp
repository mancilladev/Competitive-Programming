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
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
// F(u,0,n){F(w,0,m)cout<<array[u][w]<<" ";cout<<endl;} print Matrix
// int array[n][m] = {}; this initializes array with zeros

int main() {
    int w;
    while(cin>>w) {
        // getting inputs
        vi heights(w);
        F(i,0,w) cin>>heights[i];

        // creating zeros matrix
        ll max_h = *max_element(heights.begin(), heights.end());
        int h = min(max_h,w); // avoid unnecesarily big vector
        vector< vi > grid(h, vi(w, 0));

        // filling matrix to look as supposed
        F(i,0,w) F(j,0,min(heights[i],h)) grid[j][i] = 1;

        // dinamic change matrix to have triangles
        F(i,1,h) F(j,1,w-1) if (grid[i][j] && grid[i-1][j] == grid[i-1][j-1] && grid[i-1][j] == grid[i-1][j+1]) grid[i][j] = grid[i-1][j]+1;

        // getting and printing max value (max height of triangle)
        int ans = 0;
        F(i,0,h) {
            vi* v(&grid.at(i));
            ll temp = *max_element(v->begin(), v->end());
            if (temp<ans) break;
            ans = temp;
        }
        cout<<ans<<endl;
        
        // print matrix
        // if(w>20) continue;
        // F(i,0,max_h) { F(j,0,w) cout<<grid[i][j]<<" "; cout<<endl; }
        // cout<<endl;
    }
    return 0;
}

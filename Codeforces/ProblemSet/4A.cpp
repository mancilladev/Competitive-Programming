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
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
// F(u,0,n){F(w,0,m)cout<<array[u][w]<<" ";cout<<endl;} print Matrix
// int array[n][m] = {}; this initializes array with zeros

int main() {
    ll size;
    while(cin>>size) {
        if(size%2==0 && size>2) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}

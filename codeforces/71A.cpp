#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<string> vs;
#define INF 1000000000
#define abs(x) (x<0?(-x):x) // big bug here if "-x" is not surrounded by "()"
#define F(i,L,R) for (int i = L; i < R; i++) //next four are for "for loops"
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define FF(i,L,R) for (int i = L; i > R; i--)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
// power up C++
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define vpresent(v,x) (find(all(v),x) != (v).end())
// F(u,0,n){F(w,0,m)cout<<array[u][w]<<" ";cout<<endl;} print Matrix
// int array[n][m] = {}; this initializes array with zeros

int main() {
    ll a;
    while(cin>>a) {
        F(i,0,a) {
            string s;
            cin>>s;
            int size = s.length();
            if(size > 10) {
                cout<<s[0]<<size-2<<s[size-1]<<endl;
            } else {
                cout<<s<<endl;
            }
        }
    }
    return 0;
}

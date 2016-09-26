#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector< ii > vii;
typedef vector<int> vi;
typedef vector<string> vs;
#define INF 1000000000
#define minn(a,b,c) (min(min(a,b),min(a,c)))
#define F(i,L,R) for (int i = L; i < R; i++) //next four are for "for loops"
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define FF(i,L,R) for (int i = L; i > R; i--)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;


int main() {
    int N, P;
    while(cin>>N>>P) {
        // create matrices
        vector< vi > black(N, vi(N, 1));
        vector< vi > white(N, vi(N, 1));
        int a,b;
        F(i,0,P) {
            cin>>a>>b;
            white[a-1][b-1] = 0;
        }
        F(i,0,P) {
            cin>>a>>b;
            black[a-1][b-1] = 0;
        }

        // F(u,0,N){F(w,0,N)cout<<black[u][w]<<" ";cout<<endl;}cout<<endl;
        // F(u,0,N){F(w,0,N)cout<<white[u][w]<<" ";cout<<endl;}cout<<endl;

        // dinamicaly create matrices
        FFE(i,N-2,0) FFE(j,N-2,0) {
            int minb = minn(black[i+1][j], black[i+1][j+1], black[i][j+1]);
            int minw = minn(white[i+1][j], white[i+1][j+1], white[i][j+1]);
            if(black[i][j]) {
                black[i][j] = minb+1;
            }
            if(white[i][j]) {
                white[i][j] = minw+1;
            }
        }

        // count with Diego's method
        int ab=0, aw = 0;
        F(i,0,N) F(j,0,N) {
            ab += max(0, black[i][j]-white[i][j]);
            aw += max(0, white[i][j]-black[i][j]);
        }

        // F(u,0,N){F(w,0,N)cout<<black[u][w]<<" ";cout<<endl;}cout<<endl;
        // F(u,0,N){F(w,0,N)cout<<white[u][w]<<" ";cout<<endl;}cout<<endl;

        cout<<ab<<" "<<aw<<endl;

    }
    return 0;
}

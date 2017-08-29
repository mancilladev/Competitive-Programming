#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define spresent(str1,str2) (str1.find(str2) != string::npos)

int N, M;


void swap_cols(vector< vector<int> >& m, int col1, int col2) {
    REP(i,N) swap(m[col1], m[col2]);
}


bool solves(vector< vector<int> > m) {
    // swap in row
    REP(y,N) {
        int pos = -1;
        REP(x,M) {
            if(m[y][x] != x+1) {
                if(pos == -1) pos = x;
                else swap(m[y][x], m[y][pos]);
            }
        }
    }
    
    REP(i,N) REP(j,M) {
        if(m[i][j] != j+1) return false;
    }
    return true;
}


bool solve(vector< vector<int> >& m) {
    // try not swapping
    if(solves(m)) return true;

    // swap columns
    int pos = -1;
    REP(y,N-1) {
        REP(x,M) {
            if(m[y][x] != x+1 && m[y+1][x] != x+1){
                if(pos == -1) pos = x;
                else {
                    swap_cols(m, x, pos);
                    if(solves(m)) return true;
                    else swap_cols(m, x, pos);
                }
            }
        }
    }
    return false;
}


int main() {
    while(cin>>N>>M) {
        vector< vector<int> > m(N, vector<int>(M));
        REP(i,N) REP(j,M) cin>>m[i][j];

        bool b = solve(m);
        if(b) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

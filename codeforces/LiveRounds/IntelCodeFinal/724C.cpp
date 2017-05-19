#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define spresent(str1,str2) (str1.find(str2) != string::npos)


int main() {
    int N, M, K;
    while(cin>>N>>M>>K) {
        vector< pair<int,int> > p(K);
        pair<int,int> pos = make_pair(0,0);
        int x = 1, y = 1;

        while(true) {
            pos.first += x;
            pos.second += y;
            if((pos.first == 0 && pos.second == M) ||
                    (pos.first == N && pos.second == 0) ||
                    (pos.first == N && pos.second == M)) {
                break;
            }

            
        }
    }
}

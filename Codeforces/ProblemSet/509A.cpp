#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define spresent(str1,str2) (str1.find(str2) != string::npos)

int main() {
    int n;
    cin>>n;

    vector<int> table(n,1);
    REP(i,n-1) FOR(j,1,n-1) table[j] += table[j-1];
    cout<<table[n-1]<<endl;
}

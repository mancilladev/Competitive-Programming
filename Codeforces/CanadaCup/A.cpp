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
    int n;
    string s;
    while(cin>>n) {
        cin>>s;
        int cnt = 0;
        REP(i,n) {
            if(s[i] == '>') break;
            cnt++;
        }
        FORD(i,n-1,0) {
            if(s[i] == '<') break;
            cnt++;
        }
        cout<<cnt<<endl;
    }
}

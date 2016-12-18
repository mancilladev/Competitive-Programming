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
	ll N;
    while(cin>>N) {
        string s;
        cin>>s;

        int cnt = 0;
        FOR(i, 0, s.length()) if(s[i] == 'A') cnt++;

        int left = s.length()- cnt;
        if(cnt == left) cout<<"Friendship"<<endl;
        else if(cnt > left ) cout<<"Anton"<<endl;
        else cout<<"Danik"<<endl;
    }
}

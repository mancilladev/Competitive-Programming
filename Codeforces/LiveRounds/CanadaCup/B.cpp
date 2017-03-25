#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
typedef long long ll;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define spresent(str1,str2) (str1.find(str2) != string::npos)


int main() {
    string s;
    while(cin>>s) {
        ll N;
        char pos = s[s.length()-1];
        s.erase(s.length()-1);
        istringstream buffer(s);
        buffer>>N;

        ll a = 1, b = 3, row = 0;
        for(; a != N && b != N;) {
            if(--row%3 == 0) a += 3;
            else a++;
            b = a+2;
        }
    }
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define spresent(str1,str2) (str1.find(str2) != string::npos)

int main() {
    string s;
    while(cin>>s) {
        int up = 0, lo = 0;
        REP(i,s.length()) if(s[i] >= 'A' && s[i] <= 'Z') up++; else lo++;
        if(up > lo) transform(s.begin(), s.end(), s.begin(), ::toupper);
        else transform(s.begin(), s.end(), s.begin(), ::tolower);
        cout<<s<<endl;
    }
}

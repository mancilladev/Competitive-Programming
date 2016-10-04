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
    string k1 = "qwertyuiop";
    string k2 = "asdfghjkl;";
    string k3 = "zxcvbnm,./";

    char action;
    cin>>action;
    string code;
    cin>>code;

    string s;
    REP(i,code.length())
        if(action == 'R') {
            char c;
            if(spresent(k1,code[i])) c = k1[k1.find(code[i]) - 1];
            if(spresent(k2,code[i])) c = k2[k2.find(code[i]) - 1];
            if(spresent(k3,code[i])) c = k3[k3.find(code[i]) - 1];
            s += c;
        }
        else {
            char c;
            if(spresent(k1,code[i])) c = k1[k1.find(code[i]) + 1];
            if(spresent(k2,code[i])) c = k2[k2.find(code[i]) + 1];
            if(spresent(k3,code[i])) c = k3[k3.find(code[i]) + 1];
            s += c;
        }
    cout<<s<<endl;
}

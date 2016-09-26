#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define F(i,L,R) for(int i=L; i<R; i++)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;


bool caps_error(string s) {
    if(s.length() == 1) return true;
    F(i,1,s.length()) {
        if (islower(s[i])) return false;
    }
    return true;
}


string change(string s) {
    string ss;
    if(isupper(s[0])) ss += tolower(s[0]);
    else ss += toupper(s[0]);
    F(i,1,s.length()) ss += tolower(s[i]);
    return ss;
}


int main() {
    string s;
    while(getline(cin, s)) {
        string normal, subs;
        F(i,0,s.length()) {
            if(s[i] == ' ') {
                if(caps_error(subs)) normal += change(subs);
                else normal += subs;
                normal += ' ';
                subs = "";
            }
            else subs += s[i];
        }
        if(caps_error(subs)) normal += change(subs);
        else normal += subs;
        cout<<normal<<endl;
    }
}

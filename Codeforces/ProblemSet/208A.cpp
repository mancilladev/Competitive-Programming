#include <iostream>
#include <string>
using namespace std;
#define F(i,L,R) for(int i=L; i<R; i++)

int main() {
    string s;
    while(cin>>s) {
        string song;
        bool ok = false;
        F(i,0,s.length()){
            if(s[i]=='W' && s[i+1]=='U' && s[i+2]=='B') {
                i+=2;
                if(ok) {
                    song += " ";
                    ok = false;
                }
            }
            else {
                song += s[i];
                ok = true;
            }
        }
        if(song.back() == ' ') song.pop_back();
        cout<<song<<endl;
    }
}

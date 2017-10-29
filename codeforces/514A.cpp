#include <iostream>
#include <string>
using namespace std;


int main() {
    string S; cin>>S;
    string nmin;
    for(int i = 0; i != S.length(); i++) {
        int d = S[i] - '0';
        if(d < 5 || (i==0 && d == 9)) nmin += S[i];
        else nmin += to_string(9-d);
    }
    cout<<nmin<<endl;
}

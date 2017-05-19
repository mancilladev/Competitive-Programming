#include <string>
#include <iostream>
using namespace std;


int main() {
    string S;
    while(cin>>S) {
        for(int i = 0; i != S.length(); i++) {
            if(S[i] < 'A' || S[i] > 'Z') {
                cout<<S[i];
                continue;
            }
            int pos = S[i] - 'A';
            if(S[i] > 'R') pos--;
            if(S[i] == 'Z') pos--;
            int val = 2 + pos/3;
            cout<<val;
        }
        cout<<endl;
    }
}

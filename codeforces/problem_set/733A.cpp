#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    while(cin>>S) {
        int jump = 1;
        int cnt = 1;
        for(int i = 0; i < S.length(); i++) {
            if(S[i] == 'A' || S[i] == 'E' || S[i] == 'I' || S[i] == 'O' || S[i] == 'U' || S[i] == 'Y') {
                jump = max(jump, cnt);
                cnt = 1;
            }
            else cnt++;
        }
        jump = max(jump, cnt);
        cout<<jump;
    }
}

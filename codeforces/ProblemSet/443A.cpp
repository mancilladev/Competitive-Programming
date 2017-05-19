#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    string s;
    while(getline(cin,s)) {
        set<char> letters;
        for(int i=0; i!=s.length(); i++) {
            if(s[i] >= 'a' && s[i] <= 'z') letters.insert(s[i]);
        }
        cout<<letters.size()<<endl;
    }
}

#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main() {
    int n;
    string s;
    while(cin>>n) {
        cin>>s;

        vector<int> v;
        int cnt = 0;
        for(int i = 0; i != n; i++) {
            if(s[i] == 'B')
                cnt++;
            else {
                if(cnt) v.push_back(cnt);
                cnt = 0;
            }
        }
        if(cnt) v.push_back(cnt);

        cout<<v.size()<<endl;
        if(v.size()) {
            for(int i = 0; i < v.size()-1; i++) cout<<v[i]<<" ";
            cout<<v.back()<<endl;
        }
    }
}

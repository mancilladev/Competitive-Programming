#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define F(i,L,R) for(int i=L; i<R; i++)

int main() {
    string s;
    while(cin>>s) {
        int cur = s[0];
        ll cnt = 1;
        ll maxcnt = 1;
        if(s.length() > 7) {
            F(i,1,s.length()) {
                if(s[i] == cur) cnt++;
                else {
                    maxcnt = max(maxcnt,cnt);
                    cur=s[i];
                    cnt=1;
                }
            }
        }
        maxcnt = max(maxcnt,cnt);
        if (maxcnt<7) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}

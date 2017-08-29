#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define F(i,L,R) for(int i=L; i<R; i++)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
#define spresent(str1,str2) (str1.find(str2) != string::npos)


bool is_lucky(int n) {
    string s = to_string(n);
    F(i,0,s.length()) if(s[i] != '4' && s[i] != '7') return false;
    return true;
}


bool nearly_lucky(ll n) {
    int lucky_digits = 0;
    string s = to_string(n);
    F(i,0,s.length()) if(s[i] == '4' || s[i] == '7') lucky_digits++;
    if(is_lucky(lucky_digits)) return true;
    return false;
}


int main() {
    ll n;
    while(cin>>n) {
        if(nearly_lucky(n)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

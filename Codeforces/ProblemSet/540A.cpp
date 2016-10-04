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
    int n;
    cin>>n;
    string s1, s2;
    cin>>s1;
    cin>>s2;

    int one[n], two[n];
    REP(i,n) one[i] = s1[i] - '0';
    REP(i,n) two[i] = s2[i] - '0';

    long long res = 0;
    REP(i,n) res += min(abs(one[i]-two[i]), 10+min(one[i],two[i])-max(one[i],two[i]));
    cout<<res<<endl;
}

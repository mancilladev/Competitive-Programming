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
    int cups = 0, medls = 0;
    int temp;
    REP(i,3) { cin>>temp; cups += temp; }
    REP(i,3) { cin>>temp; medls += temp; }
    int shelves;
    cin>>shelves;

    int smin = 0;

    smin += cups/5 + (cups%5?1:0);
    smin += medls/10 + (medls%10?1:0);

    if(smin<=shelves) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

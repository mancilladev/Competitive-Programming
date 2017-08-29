#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define spresent(str1,str2) (str1.find(str2) != string::npos)

int main() {
    vector<int> days {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<string> week { "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday" };
    map<string, int> val {
        { "January",0 }
        { "February", }
        { "March", }
        { "April", }
        { "May", }
        { "June", }
        { "July", }
        { "August", }
        { "September", }
        { "October",0 }
        { "November", }
        { "December" }
    };

    string S, R;
    while(cin>>S>>R) {
        bool poss = false;


        if(poss) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

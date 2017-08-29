#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define F(i,L,R) for(int i=L; i<R; i++)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
#define spresent(str1,str2) (str1.find(str2) != string::npos)

int main() {
    int n;
    while(cin>>n) {
        int sum = 0;
        int cur = 0;
        int mincoins = 0;

        vi coins(n);
        F(i,0,n) cin>>coins[i];
        sort(coins.begin(), coins.end());

        for(auto i: coins) sum += i;
        while(cur <= sum/2) {
            cur += coins.back();
            coins.pop_back();
            mincoins++;
        }

        cout<<mincoins<<endl;
    }
}

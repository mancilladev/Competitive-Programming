#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define F(i,L,R) for(int i=L; i<R; i++)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
#define spresent(str1,str2) (str1.find(str2) != string::npos)

int main() {
    ll n;
    vector<string> v {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
    while(cin>>n) {

        int k = 0;
        while(5 * pow(2, k) < n) {
            n -= (5 * pow(2, k));
            k++;
        }

        int c = 0;
        while((c+1) * pow(2, k) < n) c++;

        cout<<v[c]<<endl;
    }
}

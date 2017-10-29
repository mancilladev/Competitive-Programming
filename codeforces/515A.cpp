#include <iostream>
using namespace std;


int main() {
    long long A, B, S;
    cin>>A>>B>>S;
    A = abs(A);
    B = abs(B);

    if(A+B <= S && (A+B-S)%2 == 0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

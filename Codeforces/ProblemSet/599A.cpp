#include <iostream>
using namespace std;


int main() {
    int A, B, C;
    cin>>A>>B>>C;

    int s = 0;
    s += min(A,B);
    s += min(A+B, C);
    s += min(max(A,B), C+min(A,B));
    cout<<s<<endl;
}

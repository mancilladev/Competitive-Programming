#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;

int main() {
    int T; cin>>T;
    while(T--) {
        int N; cin>>N;
        int res = -1;

        for(int a = 1; a < N; a++) {
            int b = ((N-a)*(N-a)-a*a)/(2*(N-a));
            int c = N-a-b;
            if(a < b && b < c && a*a + b*b == c*c) {
                res = max(res, a*b*c);
            }
        }

        cout<<res<<endl;
    }
    return 0;
}

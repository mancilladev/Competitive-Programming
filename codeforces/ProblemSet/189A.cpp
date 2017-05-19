#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, a, b, c;
    while(cin>>N>>a>>b>>c) {
        int cuts = 0;

        for(int x = 0; x*a <= N; x++)
            for(int y = 0; y*b <= N; y++) {
                int z = (N-x*a-y*b)/c;
                if(z >= 0 && x*a + y*b + z*c == N) cuts = max(cuts, x+y+z);
            }

        cout<<cuts<<endl;
    }
}

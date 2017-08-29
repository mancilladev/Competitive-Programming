#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define F(i,L,R) for(int i=L; i<R; i++)
#define FFE(i,L,R) for(int i=L; i>=R; i--)
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;

int main() {
    int n;
    while(cin>>n) {
        vector<int> v(n);
        F(i,0,n) cin>>v[i];

        int segs = 0;
        int nmax = *max_element(v.begin(), v.end());
        int nmin = *min_element(v.begin(), v.end());

        F(i,1,n) if(v[i] == nmax) { 
            while(v[0] != nmax) {
                --i;
                swap(v[i],v[i+1]);
                segs++;
            }
            break;
        }

        FFE(i,n-2,0) if(v[i] == nmin) { 
            while(v.back() != nmin) {
                ++i;
                swap(v[i],v[i-1]);
                segs++;
            }
            break;
        }

        cout<<segs<<endl;
    }
}

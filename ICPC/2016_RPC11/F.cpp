#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<string> vs;
#define INF 1000000000
#define abs(x) (x<0?(-x):x) // big bug here if "-x" is not surrounded by "()"
#define F(i,L,R) for (int i = L; i < R; i++) //next four are for "for loops"
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define FF(i,L,R) for (int i = L; i > R; i--)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
// power up C++
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(decltype((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define vpresent(v,x) (find(all(v),x) != (v).end())
#define spresent(str1,str2) (str1.find(str2) != string::npos)
// F(u,0,n){F(w,0,m)cout<<array[u][w]<<" ";cout<<endl;} print Matrix
// int array[n][m] = {}; this initializes array with zeros
// std::transform(str.begin(), str.end(), str.begin(), ::tolower); lowercase string


struct Node { int l, m, r; };


int main() {
    int N;
    while(cin>>N) {

        // get left tree
        vector<Node> vl(N+1);
        int pos;
        F(i,0,N) {
            cin>>pos;
            cin>>vl[pos].l>>vl[pos].m;
        }

        // get right tree
        int M;
        cin>>M;
        vector<Node> vr(M+1);
        F(i,0,M) {
            cin>>pos;
            cin>>vr[pos].m>>vr[pos].r;
        }

        // count side nodes from merge
        int num = 0;
        F(i,0,vl.size()) if(vl[i].l) num++;
        F(i,0,vr.size()) if(vr[i].r) num++;

        // count middle nodes
        vector<int> v {0}; // back() breaks if it has no elements
        F(i,0,max(vl.size(),vr.size())) {
            if(vl[i].m && v.back() != vl[i].m) v.push_back(vl[i].m);
            if(vr[i].m && v.back() != vr[i].m) v.push_back(vr[i].m);
        }
        num += v.size()-1; // minus our bug fix

        cout<<num<<endl;
    }
    return 0;
}

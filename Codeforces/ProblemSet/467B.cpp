#include <iostream>
#include <vector>
#include <string>
#include <bitset>
using namespace std;


int diff_bits(string a, string b) {
    int n = 0;
    for(int i = 0; i != min(a.length(), b.length()); i++)
        if(a[i] != b[i]) n++;
    return n;
}


int main() {
    int N, M, K;
    cin>>N>>M>>K;
    vector<int> v(M+1);
    vector<string> b(M+1);
    for(int i = 0; i != M+1; i++) {
        cin>>v[i];
        b[i] = bitset<20>(v[i]).to_string();
    }

    int cnt = 0;
    for(int i = 0; i != M; i++) {
        if(diff_bits(b[i], b[M]) <= K) cnt++;
    }
    cout<<cnt<<endl;
}

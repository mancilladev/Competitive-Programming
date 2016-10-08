#include <iostream>
#include <string>
#include <bitset>
using namespace std;


int main() {
    int N; cin>>N;
    int res = 0;

    string bin = bitset<32>(N).to_string();
    for(int i = 0; i != bin.length(); i++)
        if(bin[i] == '1')
            res++;

    cout<<res<<endl;
}

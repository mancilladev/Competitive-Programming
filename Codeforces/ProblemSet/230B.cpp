#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int SUPREMO = 1000001;

set<long long> prime_squares() {
    static bool arr[SUPREMO];
    for(int i = 2; i * i < SUPREMO; i++)
        if(!arr[i])
            for(int j = i*i; j < SUPREMO; j+=i)
                arr[j] = true;

    set<long long> res;
    for(int i = 2; i < SUPREMO; i++)
        if(!arr[i])
            res.insert((long long)i * i);
    return res;
}

int main() {
    set<long long> T(prime_squares());
    int N; cin>>N;
    for(int i = 0; i < N; i++) {
        long long x; cin>>x;
        if(T.find(x) != T.end()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

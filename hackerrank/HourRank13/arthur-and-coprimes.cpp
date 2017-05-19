#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
typedef long long ll;


void sieve(vector<bool>& v) {
    v[0] = 0;
    v[1] = 0;
    for(int i=2; i*i<=v.size(); i++)
        if(v[i]) for(int j=i*i; j<=v.size(); j+=i) v[j] = 0;
}


int main(){
    vector<bool> v(1000001, 1);
    sieve(v);
    set<ll> s;

    ll n;
    cin >> n;

    ll res = 0;

    for(ll k = 6; k != n; k++) {
        for(ll a = 2; a*a <= n; a++) {
            ll b = k/a;
            if(v[a] && v[b] && a != b && a*b == k) res++;
        }
    }

    cout<<res<<endl;
    return 0;
}

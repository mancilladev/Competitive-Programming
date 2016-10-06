#include <set>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


bool is_palindrome(int n) {
    string s = to_string(n);
    for(int i = 0; i != s.length(); i++)
        if(s[i] != s[s.length()-i-1])
            return false;
    return true;
}


int main() {
    set<int> pals;
    for(int a = 100; a != 1000; a++)
        for(int b = 100; b != a+1; b++)
            if(is_palindrome(a*b))
                pals.insert(a*b);

    int T; cin>>T;
    while(T--) {
        int N; cin>>N;

        set<int>::iterator it = pals.lower_bound(N-1);
        it--;
        int res = *(it);

        cout<<res<<endl;
    }
    return 0;
}

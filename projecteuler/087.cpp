#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> primes;
vector<int> isp(7072, 1);
unordered_set<ll> nums;
int lim = 50'000'000;

int main () {
    for (int i = 2; i < isp.size(); ++i) if (isp[i]) {
        primes.push_back(i);
        for (int j = i + i; j < isp.size(); j += i) isp[j] = 0;
    }

    for (auto a : primes) {
        for (auto b : primes) {
            if (a*a + b*b*b > lim) break;
            for (auto c : primes) {
                ll sum = a*a + b*b*b + c*c*c*c;
                if (sum < lim)
                    nums.insert(sum);
                else
                    break;
            }
        }
    }

    cout << nums.size() << endl;

    return 0;
}

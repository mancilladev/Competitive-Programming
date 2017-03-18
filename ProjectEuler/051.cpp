#include<iostream>
#include<vector>
#include<cmath>
#define KEY 1
using namespace std;

vector<bool> isprime(10000000, 1);
vector<int> primes;

int len(int n) {
        int cnt = 1;
        while (n /= 10)
                cnt++;
        return cnt;
}

int replaceKeys(int n, int r) {
        int k = n%10 == KEY ? r : n%10;
        n /= 10;
        while (n) {
                int tmp = n%10 == KEY ? r : n%10;
                k += (tmp)*pow(10, len(k));
                n /= 10;
        }
        return k;
}

int numKeys(int n) {
        int cnt = 0;
        while (n) {
                if (n%10 == KEY) cnt++;
                n /= 10;
        }
        return cnt;
}

int familySize(int n) {
        if (numKeys(n) == 0) return 1;
        int size = 1;
        for (int i = KEY+1; i <= 9; i++)
                if (isprime[replaceKeys(n, i)])
                        size++;
        return size;
}

int main () {
        for (int i = 2; i < isprime.size(); i++) {
                if (isprime[i]) {
                        primes.push_back(i);
                        for (int j = i*i; j < isprime.size(); j+=i)
                                isprime[j] = 0;
                }
        }

        for (auto p: primes) {
                if (familySize(p) == 8) {
                        cout<<p<<endl;
                }
        }
        return 0;
}

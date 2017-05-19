#ifdef JUDGE
#include <fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int n, k;

bool check(auto &v, int _val) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] > _val) {
            double kk = (v[i]*1.0 - _val)/(k-1);
            cnt += kk;
            if (kk - (int)kk > 0)
                cnt++;
            if (cnt > _val)
                return false;
        }
    }
    return cnt <= _val;
}

int binSearch(auto &v, int _low, int _high) {
    int left = _low;
    int right = _high;
    int mid;
    int ans = _high;
    while (left <= right) {
        mid = left + (right - left)/2;
        if (check(v, mid))
            ans = mid, right = mid - 1;
        else
            left = mid + 1;
    }
    return ans;
}

int main() {
    cin >> n;

    vector<int> v(n);
    int maxV = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        maxV = max(maxV, v[i]);
    }

    cin >> k;

    cout << (k == 1 ? maxV : binSearch(v, 0, maxV)) << endl;

    return 0;
}

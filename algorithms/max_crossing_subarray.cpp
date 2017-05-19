#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int maxx(int a, int b, int c) { return max(a, max(b, c)); }

int maxCrossingSum(vector<int> A, int low, int mid, int high) {
    int sum = 0;
    int left_sum = INT_MIN;
    for(int i = mid; i >= low; i--) {
        sum += A[i];
        left_sum = max(left_sum, sum);
    }
    sum = 0;
    int right_sum = INT_MIN;
    for(int i = mid+1; i <= high; i++) {
        sum += A[i];
        right_sum = max(right_sum, sum);
    }

    return left_sum + right_sum;
}

int maxSubarraySum(vector<int> A, int low, int high) {
    // Base case: Only one element
    if(low==high) return A[low];

    int middle = (low+high)/2;

    return maxx(maxSubarraySum(A, low, middle),
            maxSubarraySum(A, middle+1, high),
            maxCrossingSum(A, low, middle, high)
            );
}

int main() {
    vector<int> arr = {-10, 2, 3, 4, 5, 7, -1, -3};
    int max_sum = maxSubarraySum(arr, 0, arr.size());
    cout<<max_sum<<endl;
}

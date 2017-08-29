#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    int N; cin>>N;
    vector<int> s1(N), s2(N-1), s3(N-2);
    vector<int> diff(N);

    int temp;
    for(int i = 0; i != N; i++) cin>>s1[i];
    for(int i = 0; i != N-1; i++) cin>>s2[i];
    for(int i = 0; i != N-2; i++) cin>>s3[i];

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    sort(s3.begin(), s3.end());

    set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), diff.begin());
    cout<<diff[0]<<endl;

    set_difference(s2.begin(), s2.end(), s3.begin(), s3.end(), diff.begin());
    cout<<diff[0]<<endl;
}

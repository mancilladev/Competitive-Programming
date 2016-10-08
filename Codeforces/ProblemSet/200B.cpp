#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main() {
    cout.precision(13);
    int N; cin>>N;
    vector<double> v(N);
    for(int i = 0; i != N; i++)
        cin>>v[i];

    double mill = 0;

    double sum = 0;
    for(int i = 0; i != N; i++)
        sum += v[i];
    mill = sum/N;

    printf("%2.12f\n", mill);
}

#include <iostream>
#define correct(x) (x>=1 && x<=1000000000)

int main() {
    long long A, B, C, D;
    while(std::cin>>A>>B>>C>>D) {
        long long n = A;
        if (!correct(A) || !correct(B) || !correct(C) || !correct(D) || (C%A!=0) || A==B || C==D) {
            std::cout << -1 << std::endl;
            continue;
        }
        while(true) {
            // A divisor
            // B not divisor
            // C multiple
            // D not multiple
            try {
                if(n%A==0 && n%B!=0 && C%n==0 && D%n!=0) break;
                else if(n > C) { n=-1; break;}
            }
            catch(int Exception) {}
            n++;
        }
        std::cout << n << std::endl;
    }
}

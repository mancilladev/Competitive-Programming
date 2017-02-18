#include<iostream>
using namespace std;

int gcd(int a, int b) {
        return (a == 0) ? b : gcd(b%a, a);
}

int main () {
		int denproduct = 1;
		int nomproduct = 1;
		 
		for (int i = 1; i < 10; i++) {
			for (int den = 1; den < i; den++) {
				for (int nom = 1; nom < den; nom++) {
					if ((nom * 10 + i) * den == nom * (i * 10 + den)) {
						denproduct *= den;
						nomproduct *= nom;
					}
				}
			}
		}

        denproduct /= gcd(nomproduct, denproduct);

        cout<<denproduct<<endl;
}

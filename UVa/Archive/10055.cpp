#include <iostream>  
#define abs(x) (x<0?(-x):x)
int main() { long long a, b; while(std::cin>>a>>b) std::cout << abs((a-b)) << std::endl; }

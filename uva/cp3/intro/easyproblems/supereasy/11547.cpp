#include <iostream>
int main(){int tn;std::cin>>tn;for(int i;i<tn;i++){int v;std::cin>>v;int res=((v*567/9+7492)*235/47-498)/10%10;if(res<0)res*=-1;std::cout<<res<<std::endl;}return 0;}

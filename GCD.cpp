#include <iostream>

int baj(int n, int m){
    n=abs(n);
    m=abs(m);
    if(n==0)
         return m;
    return baj(m%n,n); 
}
int main() {
    int N,M;
    std::cout<<"Nermuteq N ev M tvery"<<std::endl;
    std::cin>>N>>M;
    std::cout<<baj(N,M)<<std::endl;
    return 0;
}

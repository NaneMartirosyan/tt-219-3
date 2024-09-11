#include<iostream>
using namespace std;

int baj(int n, int m)
{
    if (n == 0)
        return m;
    return baj(m % n, n);
}

int bazm(int n, int m){
  if(n==0 || m==0)
    return 0;
  return abs(n*m)/baj(n,m);
}

int main(){
  int N,M;
  cout<<"enter N and M"<<endl;
  cin>>N>>M;
  cout<<bazm(N,M);
  
  return 0;
}

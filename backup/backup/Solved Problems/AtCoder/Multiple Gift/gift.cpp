#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(void){
  ll x,y;
  cin>>x>>y;
  ll ans=0;
  while(x<=y){
    x*=2;
    ++ans;
  }
  cout<<ans<<endl;
  return 0;
}
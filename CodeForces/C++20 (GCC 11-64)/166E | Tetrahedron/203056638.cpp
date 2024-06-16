#include<bits/stdc++.h>
using namespace std;
#define int long long
 
const int maxn = 1e7;
const int mod = 1e9 + 7;
 
main(){
 int n; cin >> n;
 vector<int> f(5, 0);
 f[1] = f[2] = f[3] = 1;
 for(int i=2;i<=n;i++){
  vector<int> v(5, 0);
  for(int j=1;j<=4;j++){
   v[j] = 0;
   for(int k=1;k<=4;k++){
    if(j != k){
     v[j] = (v[j] + f[k]) % mod;
    }
   }
  }
  f = v;
 }
 cout << f[4];
 return 0;
}
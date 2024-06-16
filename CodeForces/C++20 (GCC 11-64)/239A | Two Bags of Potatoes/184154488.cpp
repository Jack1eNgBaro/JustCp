#include<bits/stdc++.h>
using namespace std;
 
int main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
 
 long long y, n, k; 
 cin >> y >> k >> n;
 
 long long i = (y + k - 1) / k * k, ok = 0;
 for(;i<=n;i+=k){
//  cout << i << ' ';
  if(i - y >= 1){
   cout << i - y << " ";
   ok = 1;
  }
 }
 if(!ok) cout << -1;
 return 0;
}
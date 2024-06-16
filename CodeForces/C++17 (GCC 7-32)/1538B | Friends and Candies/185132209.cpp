#include<bits/stdc++.h>
using namespace std;
 
int main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
 
 int tc; cin >> tc;
 while(tc--)
 {
  int n; cin >> n;
  int a[n + 1];
  int sum = 0;
  for(int i=1;i<=n;i++){
   cin >> a[i];
   sum += a[i];
  }
  if(sum % n != 0){
   cout << -1 << "\n";
  }
  else{
   sum /= n;
   int ans = 0;
   for(int i=1;i<=n;i++){
    if(a[i] > sum)++ans;
   }
   cout << ans << "\n";
  }
 }
 
 return 0;
}
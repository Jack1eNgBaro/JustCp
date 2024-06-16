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
  for(int i=1;i<=n;i++) cin >> a[i];
  
  long long ans = 0;
  int l = 1, r = 1, z = 1;
  while(r <= n)
  {
   while(l <= n && a[r] < z){
    ++l;
    --z;
   }
//   cout << l << ' ' << r << ' ' << z << "\n";
   int d = r - l + 1;
//   ans += d * (d + 1) / 2;
   ans += d;
//   if(d >= 2) --ans;
   r++;
   z++;
  }
  cout << ans << "\n";
 }
 return 0;
}
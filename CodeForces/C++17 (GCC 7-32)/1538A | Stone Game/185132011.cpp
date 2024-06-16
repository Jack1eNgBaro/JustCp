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
  int a[n + 1]; for(int i=1;i<=n;i++) cin >> a[i];
  
  int mi = 1e9, idmi = 0;
  int mx = -1e9, idmx = 0;
  
  for(int i=1;i<=n;i++)
  {
   if(a[i] > mx){
    mx = a[i]; idmx = i;
   }
   if(a[i] < mi){
    mi = a[i]; idmi = i;
   }
  }
  
  int ans = 1e9, t;
  if(idmi < idmx)
   ans = min(ans, idmi + min(n - idmx + 1, idmx - idmi));
  else
   ans = min(ans, idmx + min(n - idmi + 1, idmi - idmx));  
  
  reverse(a + 1, a + n + 1);
  for(int i=1;i<=n;i++)
  {
   if(a[i] >= mx){
    mx = a[i]; idmx = i;
   }
   if(a[i] <= mi){
    mi = a[i]; idmi = i;
   }
  }
  if(idmi < idmx)
   ans = min(ans, idmi + min(n - idmx + 1, idmx - idmi));
  else
   ans = min(ans, idmx + min(n - idmi + 1, idmi - idmx));  
  
  
  cout << ans << "\n";
 }
   
 return 0;
}
#include<bits/stdc++.h>
using namespace std;
 
int evencount(int n){
 int ans = 0;
 while(n % 2 == 1){
  n /= 2; ++ans;
 }
 return ans;
}
 
int oddcount(int n){
 int ans = 0;
 while(n % 2 == 0){
  n /= 2; ++ans;
 }
 return ans;
}
 
int main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
 
 int tc; cin >> tc;
 while(tc--)
 {
  int sum = 0, n; cin >> n;
  vector<int> c, l;
  for(int i=0;i<n;i++)
  {
   int x; cin >> x;
   if(x % 2 == 0) 
    c.push_back(x);
   else 
    l.push_back(x);
   sum += x;
  }
  if(sum % 2 == 0) cout << "0\n";
  else{
   int ans = 1e9;
   for(auto x: c) ans = min(ans, oddcount(x));
   for(auto x: l)  ans = min(ans, evencount(x)); 
   
   cout << ans << "\n";
  } 
 }
   
 return 0;
}
#include<bits/stdc++.h>
using namespace std;
 
const int mod = 1e9 + 7; 
const int maxn = 2256;
 
int dp[maxn + 1][maxn + 1];
 
vector<int> uoc(int n){
 vector<int> ans;
 for(int i=1;i<=sqrt(n);i++){
  if(n % i == 0){
   ans.push_back(i);
   if(i != n / i) 
    ans.push_back(n / i);
  }
 }
 return ans;
}
 
vector<int> fax[maxn + 1];
 
int main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
 
 int k, n; cin >> k >> n;
 for(int i=1;i<=k;i++) fax[i] = uoc(i);
  
 for(int i=1;i<=k;i++) dp[1][i] = 1;
 for(int i=2;i<=n;i++)
 {
  for(int j=1;j<=k;j++)
  {
   vector<int> v = fax[j];
   for(auto x: v){
    dp[i][j] += dp[i - 1][x];
    dp[i][j] %= mod;
   }
  }
 }
 int ans = 0;
 for(int i=1;i<=k;i++) ans = (ans + dp[n][i]) % mod;
 cout << ans % mod << "\n";
// for(int i=1;i<=n;i++) 
// {
// for(int j=1;j<=k;j++)
// {
//  cout << dp[i][j] << ' ';
// }; cout << "\n";
// }
 return 0;
}
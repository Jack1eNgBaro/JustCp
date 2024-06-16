#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
   
 ll n; cin >> n;
 ll a[2][n + 1];
 for(ll i=0;i<2;i++) for(ll j=1;j<=n;j++)  cin >> a[i][j];
 
 ll dp[2][n + 1];
 memset(dp, 0, sizeof(dp));
 
 dp[0][1] = a[0][1];
 dp[1][1] = a[1][1];
 
 for(ll i=2;i<=n;i++)
 {
  for(ll j=0;j<2;j++)
  {
   dp[j][i] 
    = max({dp[1 - j][i - 1], dp[0][i - 2], dp[1][i - 2]}) + a[j][i];
  }
 }  
 cout << max(dp[0][n], dp[1][n]);
 return 0;
}
#include<bits/stdc++.h>
using namespace std;
 
const int maxn = 1000;
int dp[maxn + 1][10005];
int main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
 
 int v1, v2; cin >> v1 >> v2;
 int n, d; cin >> n >> d;
 
 int a[n + 1];
 memset(a, 0, sizeof(a));
 a[1] = v1;
 a[n] = v2;
 
 dp[1][a[1]] = a[1];
 for(int i=-d;i<=d;i++){
  int x = a[1] + i;
  if(x <= 0) continue;
  dp[2][x] = dp[1][a[1]] + x;
//  cout << x << " " << dp[2][x] << "\n";
 }
 
 for(int i=3;i<n;i++) for(int j=0;j<=maxn;j++)
 {
  for(int k=-d;k<=d;k++)
  {
   int x = j + d;
   if(x <= 0) continue;
   for(int t=-d;t<=d;t++)
   {
    int y = x + t;
    if(y <= 0 || dp[i - 1][y] == 0) continue;
    dp[i][x] = max(dp[i][x], dp[i - 1][y] + x);
//    cout << x << ' ' << dp[i][x] << "\n";
   }
  }
 }
 
 int ans = 0;
 for(int i=-d;i<=d;i++){
  int x = a[n] + i;
  if(x <= 0) continue;
  ans = max(ans, dp[n - 1][x] + a[n]);
 }
 cout << ans;
 return 0;
}
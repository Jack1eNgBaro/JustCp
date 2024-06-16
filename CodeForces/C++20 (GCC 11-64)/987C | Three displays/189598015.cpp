#include<bits/stdc++.h>
using namespace std;
#define int long long
 
const int maxn = 3256;
int n, s[maxn + 1], a[maxn + 1];
int dp[5][maxn + 1];
 
main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
 
 cin >> n;
 for(int i=1;i<=n;i++) cin >> s[i];
 for(int i=1;i<=n;i++) cin >> a[i];
 
 for(int i=1;i<=3;i++) for(int j=1;j<=n;j++) dp[i][j] = 1e9;
 
 for(int i=1;i<=3;i++)
 {
  if(i == 1) for(int j=1;j<=n;j++) dp[i][j] = a[j];
  else{
   for(int j=i;j<=n;j++){
    for(int k=i-1;k<j;k++){
     if(s[k] < s[j] && dp[i - 1][k] + a[j] < dp[i][j]){
      dp[i][j] = dp[i - 1][k] + a[j];
     } 
    }
   }
  }
 }
 
// for(int i=1;i<=3;i++)
// {
//  for(int j=1;j<=n;j++) cout << dp[i][j] << ' ';
//  cout << '\n';
// }
 
 int ans = 1e9;
 for(int i=3;i<=n;i++) ans = min(ans, dp[3][i]);
 if(ans == 1e9) ans = -1;
 cout << ans;
 return 0;
}
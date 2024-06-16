/*
  The only thing we have to fear is fear itself.
*/
 
#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int,int>
#define bit(x, i) ((x >> i) & 1)
 
const int mod = 1e9 + 7;
const int maxn = 1e6;
const int base = 31;
 
void file()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
}
 
int n, k, d;
int dp[105][2];
 
main()
{
 file();
 cin >> n >> k >> d;
 dp[0][0] = 1;
 for(int i=1;i<=n;i++){
  for(int j=1;j<=k;j++){
   if(i < j) continue;
   dp[i][1] = (dp[i][1] + dp[i - j][1]) % mod;
   if(j >= d){
    dp[i][1] = (dp[i][1] + dp[i - j][0]) % mod;
   }else{
    dp[i][0] = (dp[i][0] + dp[i - j][0]) % mod;    
   }
  }
 } 
 
 
// for(int i=0;i<=n;i++) cout << dp[i][0] << ' '; cout << '\n';
// for(int i=0;i<=n;i++) cout << dp[i][1] << ' '; cout << '\n';
 
 cout << dp[n][1];
 return 0;
}
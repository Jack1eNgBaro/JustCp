#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int,int>
 
const int mod = 1e9 + 7;
const int maxn = 2001;
void file()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
}
 
int dp[maxn + 1][maxn + 1];
int a[maxn + 1], b[maxn + 1];
main()
{
 file();
 int n, k, p; cin >> n >> k >> p;
 for(int i=0;i<n;i++) cin >> a[i];
 sort(a, a + n);
 for(int i=0;i<k;i++) cin >> b[i];
 sort(b, b + k);
 
 for(int i=0;i<=k;i++) for(int j=0;j<=n;j++) dp[i][j] =  1e18;
 dp[0][0] = 0;
 
 for(int i=0;i<k;i++)
 {
  for(int j=0;j<n;j++)
  {
   dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]); //ko chon nguoi thu j
   int x = abs(a[j] - b[i]) + abs(b[i] - p);
   dp[i + 1][j + 1] = min(dp[i + 1][j + 1], max(dp[i][j], x)); //chon nguoi thu j
  }
 }
 
 int ans = 1e18;
 for(int i=0;i<=k;i++)
  ans = min(ans, dp[i][n]);
 cout << ans;
 return 0;
}
#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int,int>
 
const int mod = 1e9 + 7;
const int maxn = 1e6;
void file()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
}
 
int n, k, a[maxn + 1], b[maxn + 1];
int pre[maxn + 1], suf[maxn + 1], f[maxn + 1];
 
main()
{
 file();
 cin >> n >> k;
 pre[0] = f[0] = 0;
 suf[n + 1] = 0;
 
 for(int i=1;i<=n;i++) cin >> a[i];
 for(int i=1;i<=n;i++) cin >> b[i];
 
 for(int i=1;i<=n;i++){
  f[i] = f[i - 1] + a[i];
  pre[i] = pre[i - 1];
  if(b[i] == 1) pre[i] += a[i];
 }
 for(int i=n;i>=1;i--){
  suf[i] = suf[i + 1];
  if(b[i] == 1) suf[i] += a[i];
 }
 
// for(int i=1;i<=n;i++) cout << pre[i] << " "; cout << "\n";
// for(int i=1;i<=n;i++) cout << suf[i] << " "; cout << "\n";
 
 int ans = 0;
 for(int i=1;i+k-1<=n;i++)
  ans = max(ans, f[i + k - 1] - f[i - 1] + pre[i - 1] + suf[i + k]);
 cout << ans;
 return 0;
}
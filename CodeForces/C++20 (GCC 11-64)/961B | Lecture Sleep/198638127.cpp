/*
  "There is no light without dark
  There is no joy without pain
  You can't have a rainbow without a little rain"
         ~ Andrew Tate
 
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
 
int n, k;
int a[maxn + 1], b[maxn + 1], f[maxn + 1];
int pf[maxn + 1], sf[maxn + 1];
main()
{
 file();
 cin >> n >> k;
 for(int i=1;i<=n;i++){
  cin >> a[i];
  f[i] = f[i - 1] + a[i];
 }
 for(int i=1;i<=n;i++) cin >> b[i];
 
 for(int i=1;i<=n;i++){
  pf[i] = pf[i - 1];
  if(b[i] == 1) pf[i] += a[i];
 }
 
 for(int i=n;i>=1;i--){
  sf[i] = sf[i + 1];
  if(b[i] == 1) sf[i] += a[i];
 }
 
 int ans = 0;
 for(int i=1;i+k-1<=n;i++){
  int j = i + k - 1;
  int s = f[j] - f[i - 1];
  ans = max(ans, s + pf[i - 1] + sf[j + 1]);
 }
 cout << ans;
 return 0;
}
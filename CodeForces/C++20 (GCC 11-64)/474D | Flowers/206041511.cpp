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
 
int f[maxn + 1][2];
main()
{
 file();
 int tc, k; cin >> tc >> k;
/*
 0: R
 1: W
*/
 f[0][0] = 1;
 for(int i=1;i<=maxn;i++){
  f[i][0] = f[i - 1][0] + f[i - 1][1];
  if(i >= k){
   f[i][1] = f[i - k][0] + f[i - k][1];
  }
  f[i][0] %= mod;
  f[i][1] %= mod;
 }
 
 for(int j=0;j<=1;j++){
  for(int i=1;i<=maxn;i++){
   f[i][j] = (f[i][j] + f[i - 1][j]) % mod;
  }
 }
 
 while(tc--){
  int l, r; cin >> l >> r;
  if(l > r) swap(l, r);
  int x = f[r][0] - f[l - 1][0];
  int y = f[r][1] - f[l - 1][1];
  cout << ((x + y) % mod + mod) % mod << "\n";
 }
 
 return 0;
}
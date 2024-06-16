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
 
int n, m, a[maxn + 1];
int f[maxn + 1], g[maxn + 1];
 
main()
{
 file();
 cin >> n;
 for(int i=1;i<=n;i++){
  cin >> a[i]; 
  f[i] = f[i - 1] + a[i];
 }
 sort(a + 1, a + n + 1);
 for(int i=1;i<=n;i++){
  g[i] = g[i - 1] + a[i];
 }
 cin >> m;
 while(m--){
  int c, l, r; cin >> c >> l >> r;
  if(c == 1){
   cout << f[r] - f[l - 1] << "\n";
  }else{
   cout << g[r] - g[l - 1] << "\n";
  }
 }
 
 return 0;
}
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
 
const int mx = 8;
int f[maxn + 1][mx];
 
main()
{
 file();
 int n; cin >> n;
 for(int i=0;i<=n+1;i++) for(int j=0;j<=mx;j++) f[i][j] = 1e9;
 f[0][0] = 0;
 
 
 for(int i=1;i<=n;i++){
  int v; cin >> v;
  
  int x = 0; string s; cin >> s;
  for(int j=0;j<s.size();j++){
   x += (1<<(s[j]-'A'));
  }
  
  for(int j=0;j<mx;j++) f[i][j] = f[i-1][j];
  
  for(int j=0;j<mx;j++){
   f[i][j|x] = min(f[i][j|x], f[i-1][j] + v);
  }
 }
 if(f[n][7] == 1e9) f[n][7] = -1;
 cout << f[n][7];
 return 0;
}
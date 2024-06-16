#include<bits/stdc++.h>
using namespace std;
 
const int maxn = 505;
 
int n, m, q;
int a[maxn + 1][maxn + 1];
int f[maxn + 1];
 
int main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
 
 cin >> n >> m >> q;
 for(int i=1;i<=n;i++)
 {
  int ans = 0, cnt = 0;
  for(int j=1;j<=m;j++)
  {
   int x; cin >> x;
   a[i][j] = x;
   if(x == 1) ++cnt;
   else cnt = 0;
   ans = max(ans, cnt);   
  }
  f[i] = ans;
 }
// for(int i=1;i<=n;i++) cout << f[i] <<"  ";
 
 while(q--)
 {
  int x, y; cin >> x >> y;
  a[x][y] = 1 - a[x][y];
  
  int ans = 0, cnt = 0;
  for(int i=1;i<=m;i++)
  {
   if(a[x][i] == 1) ++cnt;
   else cnt = 0;
   ans = max(ans, cnt);
  }
  f[x] = ans;
  
  int res = 0;
  for(int i=1;i<=n;i++) res = max(res, f[i]);
  cout << res << "\n";
 }
 
 return 0;
}
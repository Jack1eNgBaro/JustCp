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
const int maxn = 1005;
const int base = 31;
 
void file()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
}
 
int n, m; 
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int a[maxn + 1][maxn + 1];
 
void dfs(int u, int v, int &cur){
 cur += a[u][v];
 a[u][v] = 0;
 for(int k=0;k<4;k++){
  int i = u + dx[k];
  int j = v + dy[k];
  if(i >= 1 && i <= n && j >= 1 && j <= m && a[i][j] != 0){
   dfs(i, j, cur);
  }
 }
}
 
main()
{
 file();
 int tc; cin >> tc;
 while(tc--){
  cin >> n >> m;
  for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin >> a[i][j];
  
  int ans = 0;
  for(int i=1;i<=n;i++){
   for(int j=1;j<=m;j++){
    if(a[i][j]){
     int cur = 0;
     dfs(i, j, cur);
     ans = max(ans, cur);
    }
   }
  }
  cout << ans << "\n";
 }
 return 0;
}
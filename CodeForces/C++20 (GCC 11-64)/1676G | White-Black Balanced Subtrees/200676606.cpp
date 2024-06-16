/*
  "There is no light without dark
  There is no joy without pain
  You can't have a rainbow without a little rain"
         ~ Andrew Tate
 
*/
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pii pair<int,int>
#define bit(x, i) ((x >> i) & 1)
 
const int mod = 1e9 + 7;
const int maxn = 4005;
const int base = 31;
 
void file()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
}
 
int a[maxn + 1], f[maxn + 1];
vector<int> adj[maxn + 1]; 
 
void dfs(int u, int p){
 f[u] = a[u];
 for(int v: adj[u]){
  if(v == p) continue;
  dfs(v, u);
  f[u] += f[v];
 }
}
 
int main()
{
 file();
 int tc; cin >> tc;
 while(tc--){
  int n; cin >> n;
  
  int ans = 0;
  for(int i=1;i<=n;i++){
   adj[i].clear();
   f[i] = 0;
  }
  
  for(int i=2;i<=n;i++){
   int x; cin >> x;
   adj[x].push_back(i);
   adj[i].push_back(x);
  }
   
  for(int i=1;i<=n;i++){
   char c; cin >> c;
   if(c == 'B') a[i] = -1;
   else a[i] = 1;
  }
  
  dfs(1, 1);
  for(int i=1;i<=n;i++){
   if(f[i] == 0) ans++;
//   cout << f[i] << ' ';
  }
  cout << ans << "\n";
 }
 
 return 0;
}
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
int n;
vector<int> adj[maxn + 1];
int xa[maxn + 1], f[maxn + 1], h[maxn + 1];
 
void dfs(int u, int par){
 for(int v: adj[u]){
  if(v == par) continue;
  h[v] = h[u] + 1;
  dfs(v, u);
  xa[u] = max(xa[u], xa[v] + 1);
 } 
}
 
void solve(int u, int par, int res){
 vector<int> pf, sf;
 for(int v: adj[u]){
  if(v == par) continue;
  pf.push_back(xa[v]);
  sf.push_back(xa[v]);  
 }
 
 int sz = pf.size();
 for(int i=1;i<sz;i++) pf[i] = max(pf[i], pf[i - 1]);
 for(int i=sz-2;i>=0;i--) sf[i] = max(sf[i], sf[i + 1]);
 
 int c = 0;
 for(int v: adj[u])
 {
  if(v == par) continue;
  int op1, op2;
  if(c == 0) op1 = -1e9;
   else op1 = pf[c - 1];
  if(c == sz - 1) op2 = -1e9; 
   else op2 = sf[c + 1]; 
  int ans = 1 + max(res, max(op1, op2));
  solve(v, u, ans);
  ++c;
 }
 int x;
 if(pf.size()) x = pf.back();
 else x = -1e9;
 f[u] = 1 + max(res, x);
}
 
main()
{
 file();
 int tc; cin >> tc;
 while(tc--){
  int n, k, c;
  cin >> n >> k >> c;
  for(int i=1;i<=n;i++){
   xa[i] = 0;
   h[i] = 0;
   f[i] = 0;
   adj[i].clear();
  }
  for(int i=1;i<n;i++){
   int x, y; cin >> x >> y;
   adj[x].push_back(y);
   adj[y].push_back(x);
  }
  dfs(1, 0);
 // for(int i=1;i<=n;i++) f[i] = xa[i];
  solve(1, 0, -1);
  
  int ans = 0;
  for(int i=1;i<=n;i++){
//   cout << h[i] << " ";
   ans = max(ans, f[i] * k - h[i] * c);
  }
  cout << ans << "\n";
 }
 return 0;
}
 
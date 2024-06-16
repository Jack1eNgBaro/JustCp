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
const int maxn = 2e5;
const int base = 31;
 
void file()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
}
 
int n, m;
vector<int> adj[maxn + 1];
 
vector<int> a;
int vis[maxn + 1];
void dfs(int u){
 vis[u] = 1;
 for(int v: adj[u]){
  if(vis[v] == 1) continue;
  dfs(v);
 }
}
 
int deg[maxn + 1];
void go(int u, vector<int> &a){
 a.push_back(u);
 vis[u] = 1;
 for(int v: adj[u]){
  if(vis[v] == 0) go(v, a);
 }
}
 
int main()
{
 file();
 cin >> n >> m;
 for(int i=1;i<=m;i++){
  int x, y; cin >> x >> y;
  adj[x].push_back(y);
  adj[y].push_back(x);
  deg[x]++;
  deg[y]++;
 }
 memset(vis, 0, sizeof(vis));
 for(int i=1;i<=n;i++){
  if(vis[i] == 0){
   a.push_back(i);
   dfs(i);
  }
 }
 int ans = 0;
 memset(vis, 0, sizeof(vis));
 for(auto x: a){
  vector<int> v; go(x, v);
  if(v.size() < 3) continue;
  int sz = v.size(), ok = 1;
  for(int i=0;i<sz;i++){
   if(deg[v[i]] != 2) ok = 0;
  }
  if(ok){
   ++ans;
  }
 }
 cout << ans;
 return 0;
}
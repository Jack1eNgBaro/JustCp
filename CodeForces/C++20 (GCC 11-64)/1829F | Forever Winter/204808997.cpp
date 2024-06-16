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
const int maxn = 205;
const int base = 31;
 
void file()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
}
 
int n, m, used[maxn + 1];
vector<int> adj[maxn + 1];
int f[maxn + 1];
 
void dfs(int u){
 used[u] = 1;
 f[u] = 1;
 for(int v: adj[u]){
  if(used[v] == 0){
   dfs(v);
   f[u] += f[v];
  }
 }
}
 
int isroot(int u){
 memset(f, 0, sizeof(f));
 memset(used, 0, sizeof(used));
 dfs(u);
 memset(used, 0, sizeof(used));
 
 map<int,set<int>> mp;
 map<int,int> db;
 
 queue<pii> q;
 q.push({u, 1});
 used[u] = 1;
 while(!q.empty()){
  auto it = q.front(); q.pop();
  mp[it.second].insert(f[it.first]);
  db[it.second] = adj[it.first].size();
  for(int v: adj[it.first]){
   if(used[v] == 0){
    used[v] = 1;
    q.push({v, it.second + 1});
   }
  }
 }
 int ok = 1;
 for(auto x: mp){
  if(x.second.size() > 1){
   ok = 0;
   break;
  }
 }
 return ok; 
}
 
main()
{
 file();
 int tc; cin >> tc;
 while(tc--){
  cin >> n >> m;
  for(int i=1;i<=n;i++) adj[i].clear();
  for(int i=0;i<m;i++){
   int x, y; cin >> x >> y;
   adj[x].push_back(y);
   adj[y].push_back(x);
  }
  int root = 0;
  for(int i=1;i<=n;i++){
   if(isroot(i)){
    root = i;
    break;
   }
  }
  memset(used, 0, sizeof(used));
  vector<int> v;
  queue<int> q;
  q.push(root);
  while(q.size()){
   int u = q.front(); q.pop();
   if(v.size() < 2) v.push_back(adj[u].size());
   for(int x: adj[u]){
    if(used[x] == 0){
     used[x] = 1;
     q.push(x);
    }
   }
  }
  *v.rbegin() -= 1;
  for(auto x: v) cout << x << ' '; cout << "\n";
 }
 return 0;
}
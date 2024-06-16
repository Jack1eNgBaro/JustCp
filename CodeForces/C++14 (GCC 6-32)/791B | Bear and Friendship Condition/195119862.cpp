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
 
int n, m;
vector<int> adj[maxn + 1];
 
vector<pii> edge;
int used[maxn + 1];
vector<int> flag[maxn + 1];
int d[maxn + 1], l[maxn + 1];
int idx = 0;
void dfs(int u){
 used[u] = 1;
 flag[idx].push_back(u);
 l[u] = idx;
 for(int v: adj[u]){
  if(used[v]) continue;
  dfs(v);
 }
}
 
main()
{
 file();
 cin >> n >> m;
 for(int i=0;i<m;i++){
  int x, y; cin >> x >> y;
  adj[x].push_back(y);
  adj[y].push_back(x);
  edge.push_back({x, y});
 }
 for(int i=1;i<=n;i++){
  if(used[i] == 0){
   ++idx; dfs(i);
  }
 }
 
 for(auto it: edge){
  int x = l[it.first];
  d[x]++;
 }
 
 for(int i=1;i<=n;i++){
  int x = flag[i].size();
  if(x == 0) continue;
  if(x * (x - 1) / 2 != d[i]){
   return cout << "NO\n", 0;
  }
 }
 cout << "YES\n";
 return 0;
}
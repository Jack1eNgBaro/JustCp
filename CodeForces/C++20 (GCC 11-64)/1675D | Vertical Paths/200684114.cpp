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
const int maxn = 1e6;
const int base = 31;
 
void file()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
}
 
vector<int> adj[maxn + 1];
int h[maxn + 1];
 
void dfs(int u, int p){
 for(int v: adj[u]){
  if(v == p) continue;
  h[v] = h[u] + 1;
  dfs(v, u);
 }
}
 
int cmp(int a, int b){
 return h[a] < h[b];
}
 
int root, used[maxn + 1], stop = 0;
void go(int u, int p, vector<int> &a){
 if(stop) return;
 a.push_back(u);
 used[u] = 1;
 if(adj[u].size() == 1 && u != root){
  stop = 1; return;
 }
 for(int v: adj[u]){
  if(v != p && used[v] == 0){
   go(v, u, a);
  }
 }
// return void();
}
 
int main()
{
 file();
 int tc = 1;
   cin >> tc;
 while(tc--){
  int n; cin >> n;
  
  vector<int> a;
  for(int i=1;i<=n;i++){
   a.push_back(i);
   adj[i].clear();
   used[i] = 0;
   h[i] = 0;
  }root = 0;
  
  
  for(int i=1;i<=n;i++){
   int x; cin >> x;
   if(x == i){
    root = i; continue;
   }
   adj[x].push_back(i);
   adj[i].push_back(x);
  }
  dfs(root, root);
  
  sort(a.begin(), a.end(), cmp);
//  for(auto x: a) cout << x << ' ';
 
  vector<vector<int>> ans;
  for(auto x: a){
   vector<int> v;
   if(used[x] == 0){
    stop = 0;
    go(x, x, v);
    ans.push_back(v);
   }
  }
  cout << ans.size() << "\n";
  for(auto v: ans){
   cout << v.size() << "\n";
   for(auto x: v) cout << x << " "; cout << "\n";
  }
  cout << "\n";
 }
 
 return 0;
}
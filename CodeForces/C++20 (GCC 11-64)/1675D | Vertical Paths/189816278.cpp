#include<bits/stdc++.h>
using namespace std;
 
const int maxn = 2e5;
 
int n, m;
vector<int> adj[maxn + 1];
 
vector<vector<int>> ans;
vector<int> v;
void dfs(int u, int par){
 v.push_back(u);
// cout << u << " ";
 for(int v: adj[u]){
  if(v == par) continue;
  dfs(v, u);
 }
 if(v.size()) ans.push_back(v);
 v.clear();
}
 
int main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
 
 int tc = 1;
   cin >> tc;
 while(tc--)
 {
  cin >> n;
  for(int i=1;i<=n;i++) adj[i].clear();
  ans.clear();
  
  int root = -1;
  for(int i=1;i<=n;i++){
   int x; cin >> x;
   if(x == i) root = i;
   else{
    adj[x].push_back(i);
    adj[i].push_back(x);
   }
  }
  dfs(root, 0);
  cout << ans.size() << "\n";
  for(auto v: ans){
   cout << v.size() << "\n";
   for(auto x: v) cout << x << " ";
   cout << "\n";
  }
  cout << "\n";
 }
 
 return 0;
}
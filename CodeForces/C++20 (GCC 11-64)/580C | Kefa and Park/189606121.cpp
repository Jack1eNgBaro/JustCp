#include<bits/stdc++.h>
using namespace std;
 
const int maxn = 1e5;
 
int n, m, leaf[maxn + 1], ok[maxn + 1];
vector<int> adj[maxn + 1];
 
int ans = 0;
void dfs(int u, int par, int cnt){
// cout << u << ' ' << cnt << "\n";
 if(leaf[u]){
  ++ans;
 }
 for(int v: adj[u]){
  if(v == par) continue;
  if(ok[v] == 1){
   if(cnt + 1 <= m) dfs(v, u, cnt + 1);
  }else 
   dfs(v, u, 0);
 }
}
 
int main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
 
 cin >> n >> m;
 for(int i=1;i<=n;i++){
  int x; cin >> x;
  ok[i] = x;
 }
 
// for(int i=1;i<=n;i++) if(ok[i]) cout << i << ' '; cout << "\n";
 
 for(int i=1;i<n;i++){
  int x, y; cin >> x >> y;
  adj[x].push_back(y);
  adj[y].push_back(x);
 }
 for(int i=2;i<=n;i++){
  if(adj[i].size() == 1){
   leaf[i] = 1;
//   cout << i << " ";
  }
 }
 dfs(1, 0, ok[1]);
 cout << ans << "\n";
 return 0;
}
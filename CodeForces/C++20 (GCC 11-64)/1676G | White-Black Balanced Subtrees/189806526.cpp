#include<bits/stdc++.h>
using namespace std;
 
const int maxn = 2e5;
 
vector<int> adj[maxn + 1];
int n, cb[maxn + 1], cw[maxn + 1];
string s;
 
pair<int,int> dfs(int u, int par){
 cb[u] = (s[u] == 'B');
 cw[u] = (s[u] == 'W');
 for(int v: adj[u]){
  if(v == par) continue;
  auto it = dfs(v, u);
  cb[u] += it.first;
  cw[u] += it.second;
 }
 return {cb[u], cw[u]};
}
 
int main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
 
 int tc; cin >> tc;
 while(tc--){
  cin >> n;
  for(int i=1;i<=n;i++){
   adj[i].clear();
   cb[i] = 0;
   cw[i] = 0;
  }
  for(int i=2;i<=n;i++){
   int x; cin >> x;
   adj[x].push_back(i);
   adj[i].push_back(x);
  }
  cin >> s;  s = "~" + s;
  dfs(1, 0);
  int ans = 0;
  for(int i=1;i<=n;i++){
   if(cb[i] == cw[i]) ++ans;
  }
  cout << ans <<" \n";
 }
   
 return 0;
}
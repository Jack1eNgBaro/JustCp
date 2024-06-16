#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int,int>
 
const int mod = 1e9 + 7;
const int maxn = 1e6;
void file() {
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
}
 
int n, m;
vector<int> adj[maxn + 1];
int used[maxn + 1];
 
int canh = 0, dinh = 0;
void dfs(int u){
 used[u] = 1;
 ++dinh;
 canh += adj[u].size(); 
 for(int v: adj[u]){
  if(used[v] == 0) dfs(v);
 }
}
 main() {
 file();
 cin >> n >> m;
 for(int i=0;i<m;i++){
  int x, y; cin >> x >> y;
  adj[x].push_back(y);
  adj[y].push_back(x);
 }
 
 for(int i=1;i<=n;i++){
  if(used[i] == 0){
   canh = 0; dinh = 0;
   dfs(i);
//   cout << dinh << ' ' << canh << "\n";
   if(canh != dinh * (dinh - 1)){
    cout << "NO\n";
    return 0;
   }
  }
 }
 cout << "YES\n";
 return 0;
}
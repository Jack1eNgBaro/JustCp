#include<bits/stdc++.h>
using namespace std;
 
const int maxn = 1e4;
vector<int> adj[maxn + 1];
int used[maxn + 1];
 
void dfs(int u)
{
 used[u] = 1;
 for(int v: adj[u])
  if(used[v] == 0) dfs(v);
}
 
int main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
 
 int n; cin >> n;
 int a[n + 1];
 
 for(int i=1;i<=n;i++)
 {
  int x; cin >> x;
  adj[x].push_back(i);
  adj[i].push_back(x);
 }
 
 int ans = 0;
 for(int i=1;i<=n;i++){
  if(!used[i]){
   ++ans; dfs(i);
  }
 }
 cout << ans;
 return 0;
}
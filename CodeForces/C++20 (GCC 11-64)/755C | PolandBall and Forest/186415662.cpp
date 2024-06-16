#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pii pair<int,int>
 
const int mod = 1e9 + 7;
const int maxn = 1e6;
void file()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
}
 
vector<int> adj[maxn + 1];
int used[maxn + 1];
void dfs(int u){
 used[u] = 1;
 for(int v: adj[u]){
  if(used[v] == 0) dfs(v);
 }
}
 
int main()
{
 file();
 int n; cin >> n;
 for(int i=1;i<=n;i++)
 {
  int x; cin >> x;
  adj[i].push_back(x);
  adj[x].push_back(i);
 }
 int ans = 0;
 for(int i=1;i<=n;i++)
 {
  if(!used[i]){
   dfs(i); ++ans;
  }
 }
 cout << ans;
 return 0;
}
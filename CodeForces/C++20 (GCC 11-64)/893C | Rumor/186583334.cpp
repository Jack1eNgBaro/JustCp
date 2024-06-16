#include<bits/stdc++.h>
using namespace std;
 
#define int long long
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
 
int n, q;
vector<int> adj[maxn + 1];
int used[maxn + 1], p[maxn + 1];
 
int mx;
void dfs(int u){
 used[u] = 1;
 mx = min(mx, p[u]);
 for(int v: adj[u]){
  if(used[v] == 0) dfs(v);
 }
}
 
 main()
{
 file();
 cin >> n >> q;
 for(int i=1;i<=n;i++) cin >> p[i];
 while(q--){
  int l, r; cin >> l >> r;
  adj[l].push_back(r);
  adj[r].push_back(l);
 }
 int ans = 0;
 for(int i=1;i<=n;i++){
  if(used[i] == 0){
   mx = 1e9;   
   dfs(i);
   ans += mx;
  }
 }
 cout << ans;
 return 0;
}
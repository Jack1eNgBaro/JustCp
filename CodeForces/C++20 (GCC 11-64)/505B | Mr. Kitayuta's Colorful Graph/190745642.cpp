#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pii pair<int,int>
 
const int mod = 1e9 + 7;
const int maxn = 105;
void file()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
}
 
class DSU{
 public:
  int par[maxn + 1], sz[maxn + 1];
 public:
  void makset(){
   for(int i=0;i<=maxn;i++) par[i] = i, sz[i] = 1;
  }
  int find(int v){
   if(v == par[v]) return v;
   return par[v] = find(par[v]);
  }
  void Union(int a, int b){
   a = find(a);
   b = find(b);
   if(a == b) return;
   if(sz[a] < sz[b]) swap(a, b);
   par[b] = a;
   sz[a] += sz[b];
  }
};
 
int main()
{
 file();
 DSU dsu[maxn + 1];
 for(int i=0;i<=maxn;i++) dsu[i].makset();
 int n, m; cin >> n >> m;
 for(int i=1;i<=m;i++){
  int x, y, z; cin >> x >> y >> z;
  dsu[z].Union(x, y);
 }
 int q; cin >> q;
 while(q--){
  int u, v; cin >> u >> v;
  int ans = 0;
  for(int i=0;i<=maxn;i++){
   int x = dsu[i].find(u);
   int y = dsu[i].find(v);
   ans += (x == y);
  }
  cout << ans << "\n";
 }
 return 0;
}
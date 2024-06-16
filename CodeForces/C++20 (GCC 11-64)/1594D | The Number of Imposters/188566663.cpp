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
 
int par[maxn + 1], sz[maxn + 1];
int find(int v){
 if(v == par[v]) return v;
 return par[v] = find(par[v]);
}
bool Union(int a, int b){
 a = find(a);
 b = find(b);
 if(a == b) return 0;
 if(sz[a] < sz[b]) swap(a, b);
 par[b] = a;
 sz[a] += sz[b];
 return 1;
}
 
void solve()
{
 int n, m; cin >> n >> m;
 for(int i=1;i<=n;i++){
  par[i] = i;
  sz[i] = 1;
 }
 vector<pii> a;
 for(int i=0;i<m;i++){
  int x, y; string s;
  cin >> x >> y >> s;
  if(s[0] =='c'){
   Union(x, y);
  }else{
   a.push_back({x, y});
  }
 }
 vector<int> d(n + 1, 0);
 for(auto it: a)
 {
  int u = find(it.first);
  int v = find(it.second);
  if(d[u] == 0) d[u] = v;
  if(d[v] == 0) d[v] = u;
  Union(u, d[v]);
  Union(v, d[u]);
 }
 
 for(auto it: a)
 {
  int u = it.first;
  int v = it.second;
  if(find(u) == find(v)){
   return cout << "-1\n", void();
  }
 }
 
 int ans = 0;
 for(int i=1;i<=n;i++)
 {
//  cout << i << " " << find(i) << " " << d[i] << "\n";
  if(i == find(i))
  {
   int j = find(d[i]);
   
   if(d[i] == 0) ans += sz[i];
   else if(i < j){
    ans += max(sz[i], sz[j]);
   }
  }
 }
 cout << ans << "\n";
}
 
int main()
{
 file();
 int tc; cin >> tc;
 while(tc--)
 {
  solve();
 }
 return 0;
}
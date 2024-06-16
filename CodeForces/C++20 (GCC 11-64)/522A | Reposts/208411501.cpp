/*
  The only thing we have to fear is fear itself.
*/
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pii pair<int,int>
#define bit(x, i) ((x >> i) & 1)
#define fi first
#define se second
#define vi vector<int> 
 
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
 
void lower(string &s){
 for(char &c: s){
  c = tolower(c);
 }
}
 
int idx = 2;
unordered_map<string,int> mp;
 
vector<int> adj[maxn + 1];
void nhap(){
 mp["polycarp"] = 1;
  int n; cin >> n;
  for(int i=1;i<=n;i++){
   string x, cc, y; cin >> x >> cc >> y;
  lower(x);
  lower(y);
  if(!mp.count(x)) mp[x] = idx++;
  if(!mp.count(y)) mp[y] = idx++;
 
  adj[mp[x]].push_back(mp[y]);
  adj[mp[y]].push_back(mp[x]);
  }
}
 
int f[maxn + 1];
void dfs(int u, int par){
 f[u] = 1;
 for(int v: adj[u]){
  if(v == par) continue;
  dfs(v, u);
  f[u] = max(f[u], f[v] + 1);
 }
}
 
int main()
{
 file();
 nhap();
 dfs(1, 1);
 cout << f[1];
 return 0;
}
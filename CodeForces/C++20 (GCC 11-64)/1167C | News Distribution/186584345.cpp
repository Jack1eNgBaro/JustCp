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
 
int n, m;
int par[maxn + 1], sz[maxn + 1];
int find(int v){
 if(v == par[v]) return v;
 return par[v] = find(par[v]);
}
void Union(int a, int b){
 a = find(a);
 b = find(b);
 if(a == b) return;
 if(sz[a] < sz[b]) swap(a, b);
 sz[a] += sz[b];
 par[b] = a;
}
 
int main()
{
 file(); 
 cin >> n >> m;
 for(int i=1;i<=n;i++){
  par[i] = i, sz[i] = 1;
 }
 while(m--){
  int x; cin >> x;
  vector<int> v(x);
  for(int &i: v) cin >> i;
  for(int i=1;i<v.size();i++){
   Union(v[i], v[i - 1]);
  }
 }
 for(int i=1;i<=n;i++){
  int x = find(i);
  cout << sz[x] << " ";
 }
 return 0;
}
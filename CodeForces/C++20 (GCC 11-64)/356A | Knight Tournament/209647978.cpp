/*
  The only thing we have to fear is fear itself.
*/
 
#include<bits/stdc++.h>
using namespace std;
 
#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,fma")
 
#define ll long long
#define pii pair<int,int>
#define bit(x, i) ((x >> i) & 1)
 
const int mod = 1e9 + 7;
const int maxn = 3e5 + 5;
const int base = 31;
 
void file()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
}
 
int par[maxn + 1];
int find(int v){
 if(par[v] == 0) return v;
 return par[v] = find(par[v]);
}
void Union(int a, int b){
 a = find(a); b = find(b);
 if(a == b) return;
 par[a] = b;
}
 
int a[maxn + 1];
struct query{
 int l, r, c;
};
query v[maxn + 1];
int main()
{
 file();
 int n, m; cin >> n >> m;
 for(int i=1;i<=m;++i){
  cin >> v[i].l >> v[i].r >> v[i].c;
 }
 
 for(int i=1;i<=m;i++){
  int l = v[i].l, r = v[i].r, c = v[i].c;
  while(1 + 1 == 2){
   l = find(l);
   if(l > r) break;
   if(l != c){
    a[l] = c; 
    if(a[l-1]) Union(l, l-1);
    Union(l, l+1);
   }
   ++l; 
  }
 }
 for(int i=1;i<=n;++i) cout << a[i] << " ";
 return 0;
}
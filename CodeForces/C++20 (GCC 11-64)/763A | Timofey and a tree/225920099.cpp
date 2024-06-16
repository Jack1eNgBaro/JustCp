#include<bits/stdc++.h>
 
////Ta thuat
//#pragma GCC optimize("O2")
//#pragma GCC target("avx,avx2,fma")
 
#define MOD 1000000007
#define fi first
#define se second
#define ll long long
#define ii pair<int,int>
#define Dennis ""
#define heap_max(a) priority_queue<a>
#define heap_min(a) priority_queue<a, vector<a>, greater <a>>
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define el cout << '\n'
#define rep(i, n) for(int i = 0; i < (n); i++)
#define For(i, a, b) for(int i = (a); i <= (b); i++)
#define Fod(i, a, b) for(int i = (a); i >= (b); i--)
#define bit(x, i) ((x >> i) & 1)
 
using namespace std;
template <class X, class Y> bool minimize(X &a, Y b){
    if (a > b) return a = b, true;
    return false;
}
template <class X, class Y> bool maximize(X &a, Y b){
    if (a < b) return a = b, true;
    return false;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l, int r) {return l + rng() % (r - l + 1);}
const int N = 1e6 + 5;
 
int n, a[N], f[N];
vector<int> adj[N];
vector<ii> vec;
 
int root;
map<int,int> mp[N];
 
void dfs(int u, int p=-1){
 f[u] = 1;
 for(int v: adj[u]){
  if(v == p) continue;
  dfs(v, u);
 
  if(mp[u].size() < mp[v].size()){
   swap(mp[u], mp[v]);
  }
  for(auto [x, y]: mp[v]){
   mp[u][x] += y;
  }
 
  if(f[v] == 0) f[u] = 0;
 }
 
 if(u != root){
  mp[u][a[u]]++;
  int cnt = mp[u].size();
  if(cnt > 1) f[u] = 0;
 }
}
 
int Try(int u){
 root = u;
 memset(f, 0, sizeof(f));
 For(i,1,n) mp[i].clear();
 dfs(root, -1);
 // cout << root << ' ' << f[root] << "\n";
 return f[root] == 1;
}
 
void solve(){
 cin >> n;
 For(i,2,n){
  int x, y; cin >> x >> y;
  adj[x].pb(y);
  adj[y].pb(x);
  vec.pb({x, y});
 }
 
 set<int> dbrr;
 For(i,1,n){
  cin >> a[i];
  dbrr.insert(a[i]);
 }
 if(dbrr.size() == 1){
  cout << "YES\n";
  cout << "1"; return;
 }
 
 for(auto [u, v]: vec){
  if(a[u] != a[v]){
   if(Try(u)){
    cout << "YES\n" << u;
    return;
   }
   if(Try(v)){
    cout << "YES\n" << v;
    return;
   }
   cout << "NO\n"; return;
  }
 }
 
 
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int bla = uniform_int_distribution<int>(1, 100)(rng);
    #define TASK ""
    if(fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
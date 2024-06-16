#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
#define MOD 1000000007
#define fi first
#define se second
#define int long long
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
const int N = 2e5 + 5;
 
int par[N], sz[N];
int find(int v){
 if(v == par[v]) return v;
 return par[v] = find(par[v]);
}
int Union(int a, int b){
 a = find(a);
 b = find(b);
 if(a == b) return 0;
 if(sz[a] < sz[b]) swap(a, b);
 par[b] = a;
 sz[a] += sz[b];
 return 1;
}
 
int n, m;
struct edge{
 int u, v, w, id;
};
int cmp(edge a, edge b){
 return a.w < b.w;
}
 
edge a[N];
int ok[N], st[N][21], val[N][21], h[N], ans[N];
vector<ii> adj[N];
 
void dfs(int u, int p=-1){
 // cout << u << ' ';
 for(ii it: adj[u]){
  int v = it.fi;
  int w = it.se;
  if(v == p) continue;
  st[v][0] = u;
  val[v][0] = w;
  h[v] = h[u] + 1;
  dfs(v, u);
 }
}
 
void build(){
 for(int j=1;(1<<j)<=n;j++){
  for(int i=1;i<=n;i++){
   if(st[i][j - 1]){
    st[i][j] = st[st[i][j-1]][j-1];
    val[i][j] = max(val[i][j-1], val[st[i][j-1]][j-1]);
   }
  }
 }
}
 
int get(int u, int v){
 if(h[u] < h[v]) swap(u, v);
 int ans = -1e9;
 for(int i=log2(h[u]);i>=0;i--){
  if(h[u] >= h[v] + (1<<i)){
   ans = max(ans, val[u][i]);
   u = st[u][i];
  }
 }
 if(u == v) return ans; 
 for(int i=log2(h[u]);i>=0;i--){
  if(st[u][i] != 0 && st[u][i] != st[v][i]){
   ans = max(ans, val[u][i]);
   ans = max(ans, val[v][i]);
   u = st[u][i];
   v = st[v][i];
  }
 }
 ans = max(ans, max(val[u][0], val[v][0]));
 return ans;
}
 
 
void solve(){
    cin >> n >> m;
    For(i,0,N-1){
     par[i] = i; sz[i] = 1;
    }
    For(i,1,m){
     int x, y, w; cin >> x >> y >> w;
     a[i] = {x, y, w, i};
    }
    sort(a + 1, a + m + 1, cmp);
 
    int mst1 = 0;
    vector<edge> mst;
    For(i,1,m){
     if(mst.size() == n-1)break;
     if(Union(a[i].u, a[i].v)){
      mst1 += a[i].w;
      ok[a[i].id] = 1;
      mst.push_back(a[i]);
     }
    }
    For(i,1,m){
     if(ok[a[i].id]){
      int u = a[i].u;
      int v = a[i].v;
      int w = a[i].w;
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
     }
    }
    dfs(1, 0);
    build();
    int mst2 = 1e9;
     For(i,1,m){
      if(ok[a[i].id]) ans[a[i].id] = mst1;
      else{
       int t = get(a[i].u, a[i].v);
      ans[a[i].id] =  mst1 - t + a[i].w;
      }
     }
    For(i,1,m) cout << ans[i] << "\n";
}
 
main(){
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